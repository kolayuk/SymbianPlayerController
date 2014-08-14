/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Music Player stautus observer
*
*/


#include "mpxplaybackutility.h"
#include <mpxplaybackmessage.h>
#include <mpxmedia.h>
#include <mpxmediageneraldefs.h>
#include <mpxmediamusicdefs.h>
#include <mpxplaybackframeworkdefs.h>
#include <mpxmessagegeneraldefs.h>
//#include <mpxplaybackmessagedefs.h>
//#include <mpxalbumartutil.h>
//#include <mpxlog.h>
#include <QDebug>
#include "aiplayerpluginengine.h"

// ======== MEMBER FUNCTIONS ========

// ---------------------------------------------------------------------------
// CAiPlayerPluginEngine::ConstructL
// ---------------------------------------------------------------------------
//

MMPXPlaybackUtility* CAiPlayerPluginEngine::getUtility()
{
    return iPlaybackUtility;
}

void CAiPlayerPluginEngine::ConstructL(TPlayerType playerType)
    {
    //MPX_DEBUG1("CAiPlayerPluginEngine::ConstructL");
    // Get the playback utility instance from engine.
    //iPlaybackUtility = MMPXPlaybackUtility::NewL( KPbModeActivePlayer, this );
    if (playerType==EVideoPlayer){
        iPlaybackUtility = MMPXPlaybackUtility::NewL( EMPXCategoryVideo, KPbModeActivePlayer,this);
    }
    else if (playerType==EMusicPlayer){
        iPlaybackUtility = MMPXPlaybackUtility::NewL( KMusicPlayerAppUid, this);
    }
    else{
        qDebug()<<"You should pass EMusicPlayer or EVideoPlayer as second parameter";
        Q_ASSERT(0);
    }
    //iAlbumArtUtil = CMPXAlbumArtUtil::NewL();
    if (iPlaybackUtility->StateL() == EPbStatePlaying)
        {
    	  TRAPD(err,RequestMediaL());
    	  if (err)
    		  {
    		  TBuf<255> txt;
    		  txt.Copy(_L("Req Media: "));
    		  txt.AppendNum(err);
    		  User::InfoPrint(txt);
    		  }
    	  
        }
    }

// ---------------------------------------------------------------------------
// CAiPlayerPluginEngine::NewL
// ---------------------------------------------------------------------------
//
CAiPlayerPluginEngine* CAiPlayerPluginEngine::NewL( 
        MAiPlayerPluginEngineObserver& aObserver, TPlayerType playerType)
    {
    //MPX_DEBUG1("CAiPlayerPluginEngine::NewL");
    CAiPlayerPluginEngine* self = new ( ELeave ) 
            CAiPlayerPluginEngine( aObserver );
    CleanupStack::PushL( self );
    self->ConstructL(playerType);
    CleanupStack::Pop( self );
    return self;
    }

// ---------------------------------------------------------------------------
// CAiPlayerPluginEngine::CAiPlayerPluginEngine
// ---------------------------------------------------------------------------
//
CAiPlayerPluginEngine::CAiPlayerPluginEngine( 
        MAiPlayerPluginEngineObserver& aObserver )
    : iObserver( &aObserver ),
      iPlaybackUtility( NULL ),
      iTitle( NULL ),
      iArtist( NULL ),
      iUri( NULL ),
      iMedia( NULL ),
      iPosition( KErrNotFound ),
      iDuration( KErrNotFound ),
      iExtractingAlbumArt( EFalse ),
      iSkipping( EFalse )
    {
    }

// ---------------------------------------------------------------------------
// CAiPlayerPluginEngine::~CAiPlayerPluginEngine
// ---------------------------------------------------------------------------
//
CAiPlayerPluginEngine::~CAiPlayerPluginEngine()
    {
    //MPX_DEBUG1("CAiPlayerPluginEngine::~CAiPlayerPluginEngine");
    if ( iPlaybackUtility )
        {
    	//iPlaybackUtility->CancelRequest();
    	//iPlaybackUtility->ClearSubscriptionsL();
    	//iPlaybackUtility->RemoveObserverL(*this);
    	//iPlaybackUtility->Close();
        //iPlaybackUtility=NULL;
        }
    if (iMedia){delete iMedia;}
    if (iTitle){delete iTitle;}
    if (iArtist){delete iArtist;}
    if (iUri){delete iUri;} 
    }

// ---------------------------------------------------------------------------
// From MMPXPlaybackObserver
// Handle playback message.
// ---------------------------------------------------------------------------
//
void CAiPlayerPluginEngine::HandlePlaybackMessage( CMPXMessage* aMessage, 
        TInt aError )
    {
    if ( aError == KErrNone && aMessage )
        {
        TRAP_IGNORE( DoHandlePlaybackMessageL( *aMessage ) );
        }
    }

// ---------------------------------------------------------------------------
// From MMPXPlaybackCallback
// Handle playback property.
// ---------------------------------------------------------------------------
//
void CAiPlayerPluginEngine::HandlePropertyL( TMPXPlaybackProperty aProperty, 
        TInt aValue, TInt aError )
    {
    DoHandlePropertyL( aProperty, aValue, aError );
    }

// ---------------------------------------------------------------------------
// From MMPXPlaybackCallback
// Method is called continously until aComplete=ETrue, signifying that
// it is done and there will be no more callbacks
// Only new items are passed each time
// ---------------------------------------------------------------------------
//
void CAiPlayerPluginEngine::HandleSubPlayerNamesL(
    TUid /* aPlayer */,
    const MDesCArray* /* aSubPlayers */,
    TBool /* aComplete */,
    TInt /* aError */ )
    {
    // do nothing
    }

// ---------------------------------------------------------------------------
// From MMPXPlaybackCallback
// Handle media
// ---------------------------------------------------------------------------
//
void CAiPlayerPluginEngine::HandleMediaL( const CMPXMedia& aMedia, 
        TInt aError )
    {
    //MPX_DEBUG1("CAiPlayerPluginEngine::HandleMediaL");
    if ( KErrNone == aError )
        {
        delete iUri;
        iUri = NULL;
        if (aMedia.IsSupported(KMPXMediaGeneralUri))
            {
            TParsePtrC filePath(aMedia.ValueText(KMPXMediaGeneralUri) );
            iUri = filePath.FullName().AllocL();
            }
        
		delete iTitle;
		iTitle = NULL;
        if ( aMedia.IsSupported( KMPXMediaGeneralTitle ) )
            {
            iTitle = ( aMedia.ValueText( KMPXMediaGeneralTitle ) ).AllocL();
            }
        else if ( aMedia.IsSupported( KMPXMediaGeneralUri ) )
            {
            TParsePtrC filePath( aMedia.ValueText( KMPXMediaGeneralUri ) );
            iTitle = (filePath.Name()).AllocL();
            }
		delete iArtist;
		iArtist = NULL;
		iArtist = ( aMedia.ValueText( KMPXMediaMusicArtist ) ).AllocL();
		
		iObserver->TrackInfoChanged( *iTitle, *iArtist );
        
		if (!iSkipping)
            {
            if (iExtractingAlbumArt)
                {
                //iAlbumArtUtil->CancelRequest();
                iExtractingAlbumArt=EFalse;
                }
            /*
            if ( aMedia.IsSupported( KMPXMediaMusicAlbumArtFileName ) )
                {
                delete iMedia;
                iMedia=NULL;
                iMedia = CMPXMedia::NewL( aMedia );
             
                TRAPD(err,iAlbumArtUtil->ExtractAlbumArtL(
                        *iMedia,
                        *this,
                        TSize(70,70)));
                
                if (err != KErrNone)
                    {
                    iObserver->AlbumArtChanged(NULL);
                    }
                }
            else
                {
                iObserver->AlbumArtChanged(NULL);
                }
                */
            }
		else
		    {
		    iObserver->AlbumArtChanged(NULL);
		    }
        }
    }

// ---------------------------------------------------------------------------
// From MMPXPlaybackCallback
// Handle completion of a asynchronous command
// ---------------------------------------------------------------------------
//
void CAiPlayerPluginEngine::HandlePlaybackCommandComplete( 
        CMPXCommand* /*aCommandResult*/, TInt /*aError*/ )
    {
    // do nothing
    }

// ---------------------------------------------------------------------------
// From MMPXAlbumArtUtilObserver
// Notify that extraction of album art started.
// ---------------------------------------------------------------------------
//
void CAiPlayerPluginEngine::ExtractAlbumArtStarted()
    {
    iExtractingAlbumArt = ETrue;
    }

// ---------------------------------------------------------------------------
// From MMPXAlbumArtUtilObserver
// Notify that the extraction of album art has completed.
// ---------------------------------------------------------------------------
//
void CAiPlayerPluginEngine::ExtractAlbumArtCompleted( 
        CFbsBitmap* aBitmap, 
        TInt aErr )
    {
    if (aErr == KErrNone)
        {
        iObserver->AlbumArtChanged(aBitmap);
        }
    else
        {
        iObserver->AlbumArtChanged(NULL);
        }
    iExtractingAlbumArt = EFalse;
    }

// ---------------------------------------------------------------------------
// Get the current state of the active player
// ---------------------------------------------------------------------------
//
TMPXPlaybackState CAiPlayerPluginEngine::PlayerState()
    {
    //MPX_DEBUG1( "CAiPlayerPluginEngine::PlayerState" );
    TMPXPlaybackState state( EPbStateNotInitialised );
    TRAPD(err, state = iPlaybackUtility->StateL() );
    if (err)
    	{
    	TBuf<255> txt;
    	txt.AppendNum(err);
    	User::InfoPrint(txt);
    	}
    return state;
    }

// ---------------------------------------------------------------------------
// CAiPlayerPluginEngine::TitleL
// ---------------------------------------------------------------------------
//
const TDesC& CAiPlayerPluginEngine::TitleL()
    {

    if ( iTitle )
        {
        return *iTitle;
        }
     else
        {
        RequestMediaL();
        return KNullDesC;
        }
    }

// ---------------------------------------------------------------------------
// CAiPlayerPluginEngine::Artist
// ---------------------------------------------------------------------------
//
const TDesC& CAiPlayerPluginEngine::Artist()
    {
    if ( iArtist )
        {
        return *iArtist;
        }
     else
        {
        return KNullDesC;
        }
    }
// ---------------------------------------------------------------------------
// CAiPlayerPluginEngine::Artist
// ---------------------------------------------------------------------------
//
const TDesC& CAiPlayerPluginEngine::Uri()
    {
    if ( iUri )
        {
        return *iUri;
        }
     else
        {
        return KNullDesC;
        }
    }

// ----------------------------------------------------
// CAiPlayerPluginEngine::Position
// ----------------------------------------------------
//
TInt CAiPlayerPluginEngine::Position()
    {
    return iPosition;
    }

// ----------------------------------------------------
// CAiPlayerPluginEngine::Duration
// ----------------------------------------------------
//
TInt CAiPlayerPluginEngine::Duration()
    {
    return iDuration;
    }

// ---------------------------------------------------------------------------
// Handle playback message.
// ---------------------------------------------------------------------------
//
void CAiPlayerPluginEngine::DoHandlePlaybackMessageL( 
        const CMPXMessage& aMessage )
    {
    //MPX_DEBUG1("CAiPlayerPluginEngine::DoHandlePlaybackMessageL");

    TMPXMessageId id( 
            aMessage.ValueTObjectL<TMPXMessageId>( KMPXMessageGeneralId ) );
    if ( KMPXMessageGeneral == id )
        {
        TInt event( aMessage.ValueTObjectL<TInt>( KMPXMessageGeneralEvent ) );
        //MPX_DEBUG2( "CAiPlayerPluginEngine::DoHandlePlaybackMessageL(%d)", 
        //        event );
        switch ( event )
            {
            case TMPXPlaybackMessage::EPropertyChanged:
                {
                TInt error( KErrNone );
                DoHandlePropertyL(
                    aMessage.ValueTObjectL<TInt>( KMPXMessageGeneralType ),
                    aMessage.ValueTObjectL<TInt>( KMPXMessageGeneralData ),
                    error );
                break;
                }
            case TMPXPlaybackMessage::EStateChanged:
                {
				TMPXPlaybackState state(aMessage.ValueTObjectL<TMPXPlaybackState>(KMPXMessageGeneralType ));
                //MPX_DEBUG2("CAiPlayerPluginEngine::HandlePlaybackMessageL - E"
                  //      "StateChanged(%d)", state);

                DoHandleStateChangedL( state );
                break;
                }
            case TMPXPlaybackMessage::EMediaChanged:
            case TMPXPlaybackMessage::EPlaylistUpdated:
                {
                iPlaybackUtility->PropertyL( *this, EPbPropertyPosition );
                iPlaybackUtility->PropertyL( *this, EPbPropertyDuration );
                RequestMediaL();
                break;
                }
            case TMPXPlaybackMessage::ECommandReceived:
                {
                //MPX_DEBUG2("CAiPlayerPluginEngine::HandlePlaybackMessageL - E"
                //        "CommandReceived(%d)",
                 //   aMessage.ValueTObjectL<TInt>( KMPXMessageGeneralType ) );
                break;
                }
            case TMPXPlaybackMessage::EActivePlayerChanged:
                {
               // MPX_DEBUG3("CAiPlayerPluginEngine::HandlePlaybackMessageL - E"
               //         "ActivePlayerChanged(%d, %d)",
               //     aMessage.ValueTObjectL<TInt>( KMPXMessageGeneralType ), 
               //     aMessage.ValueTObjectL<TInt>( KMPXMessageGeneralData ) );
                iPlaybackUtility->PropertyL( *this, EPbPropertyPosition );
                iPlaybackUtility->PropertyL( *this, EPbPropertyDuration );
                DoHandleStateChangedL( iPlaybackUtility->StateL() );
                // refresh media property
                RequestMediaL();
                break;
                }
            case TMPXPlaybackMessage::ESkipping:
                {
               // MPX_DEBUG1( "CAiPlayerPluginEngine::DoHandlePlaybackMessageL - ESkipping");
               // iAlbumArtUtil->CancelRequest();
                iObserver->Opening();
                iSkipping =ETrue;
                break;
                }
            case TMPXPlaybackMessage::ESkipEnd:
                {
                //MPX_DEBUG1( "CAiPlayerPluginEngine::DoHandlePlaybackMessageL - ESkipEnd()");
                iSkipping = EFalse;
                break;
                }
            default:
                {
                break;
                }
            }
        }
    }

// ---------------------------------------------------------------------------
// Handle playback property.
// ---------------------------------------------------------------------------
//
void CAiPlayerPluginEngine::DoHandlePropertyL( TInt aProperty, TInt aValue, 
        TInt aError )
    {
   // MPX_DEBUG4("CAiPlayerPluginEngine::DoHandlePropertyL - Property(%d); Valu"
           // "e(%d); Error(%d)", aProperty, aValue, aError );
    if ( KErrNone == aError )
        {
        switch ( aProperty	)
            {
            case EPbPropertyPosition:
                {
				iPosition = aValue / KMPXOneSecInMilliSecs;
                iObserver->PlaybackPositionChanged( iPosition );
                break;
                }
            case EPbPropertyDuration:
                {
				iDuration = aValue / KMPXOneSecInMilliSecs;
                break;
                }
            default:
                {
                break;
                }
            }
        }
    }

// ---------------------------------------------------------------------------
// Handle playback state changed.
// ---------------------------------------------------------------------------
//
void CAiPlayerPluginEngine::DoHandleStateChangedL( TMPXPlaybackState aState )
    {
   // MPX_DEBUG3("CAiPlayerPluginEngine::DoHandleStateChangedL - State mapped "
          //  "from (%d) to (%d)", aState, state );
        iObserver->PlayerStateChanged(aState);
    }

// ---------------------------------------------------------------------------
// Displays error notes.
// ---------------------------------------------------------------------------
//
void CAiPlayerPluginEngine::HandleErrorL( TInt aError )
    {
	//MPX_DEBUG2(("CAiPlayerPluginEngine::HandleErrorL(%d)", aError );
    }

// ---------------------------------------------------------------------------
// Map states from TMPXPlaybackState to TMPlayerState
// ---------------------------------------------------------------------------
//
TMPXPlaybackState CAiPlayerPluginEngine::MapState( TMPXPlaybackState aState )
    {
	
    return aState;
    }

// ---------------------------------------------------------------------------
// Requests Media.
// ---------------------------------------------------------------------------
//
void CAiPlayerPluginEngine::RequestMediaL()
    {
  //  MPX_DEBUG1( "CAiPlayerPluginEngine::RequestMediaL" );
    MMPXSource* s = iPlaybackUtility->Source();
    if ( s )
        {
        RArray<TMPXAttribute> attrs;
        CleanupClosePushL(attrs);
        attrs.Append( KMPXMediaGeneralUri );
        attrs.Append( KMPXMediaGeneralTitle );
        attrs.Append( KMPXMediaMusicArtist );
        attrs.Append( KMPXMediaMusicAlbumArtFileName );
        s->MediaL( attrs.Array(), *this );
        CleanupStack::PopAndDestroy( &attrs );
        }
    else 
        {
        iObserver->PlaylisIsEmpty();
        }
    }
//  End of File
