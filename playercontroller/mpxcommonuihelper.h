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
* Description:  Definition of helper utility for Common UI
*
*/



#ifndef C_CMPXCOMMONUIHELPER_H
#define C_CMPXCOMMONUIHELPER_H

#ifdef __ENABLE_MSK
#include <eikbtgpc.h>
#endif // __ENABLE_MSK
#include <mpxcollectionuihelperobserver.h>
#include <mpxcollectionuihelper.h>
#include <mpxcommonui.rsg>

// FORWARD DECLARATIONS
class CMPXMedia;
class CMPXDrmUiHelper;
class MProgressDialogCallback;
class CAknWaitDialog;
class MMPXCollectionUtility;
class CEikButtonGroupContainer;

// CONSTANTS

// CLASS DECLARATION

/**
 * Common UI helper utility class.
 *
 * @lib mpxcommonui.lib
 * @since S60 3.2.3
 */
NONSHARABLE_CLASS( CMPXCommonUiHelper ) : public CBase,
                                          public MMPXCHelperObserver
    {
public:

    /**  Duration display mode */
    enum TMPXDuratDisplayMode
        {
        EMPXDuratAuto = 0,
        EMPXDuratHMS
        };

    /**
    * Two-phased constructor.
    *
    * @since S60 3.2.3
    * @aCollectionUtility Collection utility to use for this helper
    * @return Pointer to newly created object.
    */
    IMPORT_C static CMPXCommonUiHelper* NewL(MMPXCollectionUtility* aCollectionUtility = NULL);

    /**
    * Destructor.
    */
    virtual ~CMPXCommonUiHelper();

    /**
    * Check if the host application is messaging or browser
    * @since S60 3.2.3
    * @return ETrue if host is messaging or browser, EFalse otherwise
    */
    IMPORT_C TBool IsHostMessagingBrowserL();

    /**
    * Check if the host application is the Podcasting Application
    * @since S60 3.2.3
    * @return ETrue if host is Podcasting Application, EFalse otherwise
    */
    IMPORT_C TBool IsHostPodcastingAppL();

    /**
    * Check if the host application is messaging
    * @since S60 3.2.3
    * @return ETrue if host is messaging, EFalse otherwise
    */
    IMPORT_C TBool IsHostMessagingL();

    /**
    * Check if the host application is browser
    * @since S60 3.2.3
    * @return ETrue if host is browser, EFalse otherwise
    */
    IMPORT_C TBool IsHostBrowserL();

    /**
    * Convert to displayable duration
    *
    * @since S60 3.2.3
    * @param aduration Duration in seconds
    * @param aMode time display mode
    * @return A heap descriptor that contains displayable duration
    *         (ownership transferred). Caller must destroy this object
    *         after use.
    */
    IMPORT_C HBufC* DisplayableDurationL(
        TInt64 aDuration,
        TMPXDuratDisplayMode aMode = EMPXDuratAuto );

    /**
    * Convert to displayable duration in text format
    *
    * @since S60 3.2.3
    * @param aduration Duration in seconds
    * @return A heap descriptor that contains displayable duration
    *         (ownership transferred). Caller must destroy this object
    *         after use.
    */
    IMPORT_C HBufC* DisplayableDurationInTextL(
        TInt64 aDuration );

    /**
    * Set current file as ringing tone.
    *
	* @since S60 3.2.3
    * @param aMedia Media properties of the current track. the media must
    *               contain the following attributes:
    *               TMPXAttribute( KMPXMediaIdGeneral, EMPXMediaGeneralUri )
    *               TMPXAttribute( KMPXMediaIdGeneral, EMPXMediaGeneralTitle )
    *               TMPXAttribute( KMPXMediaIdDrm, EMPXMediaDrmProtected )
    *               TMPXAttribute( KMPXMediaIdDrm, EMPXMediaDrmRightsStatus )
    *               TMPXAttribute( KMPXMediaIdDrm, EMPXMediaDrmCanSetAutomated )
    * @param aSetToAllProfiles ETrue if set ringtone to all profiles.
    *                          EFalse if set ringtone to active profile.
    * @param aShowQuery If ETrue, a confirmation query is shown before
    *                   setting ringtone. This setting will only apply if
    *                   aSetToAllProfiles is set to ETrue. No effect if
    *                   aSetToAllProfiles is set to EFalse.
    */
    IMPORT_C void DoSetAsRingingToneL(
        const CMPXMedia& aMedia,
        TBool aSetToAllProfiles,
        TBool aShowQuery = EFalse );

    /**
    * Check if current profile mode is offline mode.
    *
    * @since S60 3.2.3
    * @return ETrue if in Offline mode. Otherwise, EFalse.
    */
    IMPORT_C TBool IsProfileOfflineModeL();

    /*
    * Returns path of the default drive used to store playlist, attachments,
    * downloads and ringtones.
    * @return a path of the default drive
    * @since S60 3.2.3
    */
    IMPORT_C HBufC* DefaultDriveLC();

    /*
    * Returns a path of the next available drive used for saving playlists, ringtones,
    * downloads and attachments. The order of priority is internal mass store,
    * MMC, then phone memory.
    *
    * @since S60 3.2.3
    * @param aSize
    */
    IMPORT_C HBufC* AvailableDriveLC( TInt aSize );

    /**
    * Display information note
    *
    * @since S60 3.2.3
    * @param aResourceId Resource id of the text string
    */
    IMPORT_C void DisplayInfoNoteL( TInt aResourceId );

    /**
    * Display information note
    *
    * @since S60 3.2.3
    * @param aText Text to be shown on the note
    */
    IMPORT_C void DisplayInfoNoteL( const TDesC& aText );

    /**
    * Display confirmation note
    *
    * @since S60 3.2.3
    * @param aResourceId Resource id of the text string
    */
    IMPORT_C void DisplayConfirmNoteL( TInt aResourceId );

    /**
    * Display confirmation note
    *
    * @since S60 3.2.3
    * @param aText Text to be shown on the note
    */
    IMPORT_C void DisplayConfirmNoteL( const TDesC& aText );

// Cover UI start
//#ifdef __COVER_DISPLAY
    void DisplayConfirmNoteL( const TDesC& aText, TInt aResourceId );
//#endif // __COVER_DISPLAY
// Cover UI end

    /**
    * Convert a value from bytes to kB/MB/GB.
    *
    * @since S60 3.2.3
    * @param aByte Number of bytes
    * @param ETrue to append " free" at the end of the string
    */
    IMPORT_C HBufC* UnitConversionL( TInt64 aByte, TBool aFree = EFalse );

    /**
    * Finds all user playlists in the given collection
    *
    * @since S60 3.2.3
    */
    IMPORT_C CMPXMedia* FindPlaylistsL();

    /**
    * Add to saved playlist
    *
    * @since S60 3.2.3
    * @param aPlaylists media containing a media array
    *         each entry in the array must contain the following attributes
    *         TMPXAttribute( KMPXMediaIdGeneral, EMPXMediaGeneralTitle )
    *         TMPXAttribute( KMPXMediaIdGeneral, EMPXMediaGeneralId )
    *         TMPXAttribute( KMPXMediaIdGeneral, EMPXMediaGeneralDrive )
    * @param aTracks Tracks to be add to the playlist
    *          media containing a media array
    *          must contain at least 1 element
    *          each entry in the arry must contain the following attributes
    *          TMPXAttribute( KMPXMediaIdGeneral, EMPXMediaGeneralType )
    *          TMPXAttribute( KMPXMediaIdGeneral, EMPXMediaGeneralCategory )
    *          TMPXAttribute( KMPXMediaIdGeneral, EMPXMediaGeneralId )
    *          TMPXAttribute( KMPXMediaIdGeneral, EMPXMediaGeneralTitle )
    * @param aObserver pointer to callback
    * @param aCallback call back for wait dialog
    *
    * @return ETrue if the user accepts the save dialog, EFalse otherwise
    */
    IMPORT_C TBool AddToSavedPlaylistL(
        const CMPXMedia& aPlaylists, const CMPXMedia& aTracks,
        MMPXCHelperObserver* aObserver,
        MProgressDialogCallback* aCallback );

    /**
    * Create new playlist
    *
    * @since S60 3.2.3
    * @param aTracks Tracks to be add to the playlist
    *          media containing a media array
    *          can be a valid array with 0 length
    *          each entry in the arry must contain the following attributes
    *          TMPXAttribute( KMPXMediaIdGeneral, EMPXMediaGeneralType )
    *          TMPXAttribute( KMPXMediaIdGeneral, EMPXMediaGeneralCategory )
    *          TMPXAttribute( KMPXMediaIdGeneral, EMPXMediaGeneralId )
    *          TMPXAttribute( KMPXMediaIdGeneral, EMPXMediaGeneralTitle )
    * @param aObserver pointer to callback
    * @param aCallback call back for wait dialog
    *
    * @return ETrue if user accepts the query, EFalse otherwise
    */
    IMPORT_C TBool CreatePlaylistL( const CMPXMedia& aTracks,
        MMPXCHelperObserver* aObserver,
        MProgressDialogCallback* aCallback );

    /**
	* Launches rename dialog
	*
	* @since S60 3.2.3
	* @param aOldName original name, with the extension (e.g. a.mp3)
	* @param aNewName on return, this will be populated with the new name
	*                 inputed by the user
	* @param aPath    the path to the file, without the file name (e.g. c:\\data\\)
	* @return generic return code from AknDialog
	*/
	IMPORT_C TInt LaunchRenameDialogL(
        const TDesC& aOldName,
		TDes& aNewName,
		const TDesC& aPath );

    /**
    * Shows wait note
    *
    * @since S60 3.2.3
    * @param aText text to display
    * @param aCBAId button group ID
    * @param aVisibilityDelayOff If set ETrue the dialog will be visible
    *                            immediality. Use only when the length of
    *                            the process is ALWAYS over 1.5 seconds.
    * @param aCallback call back
    * @param aResId resource Id for the WaitNote, default is R_MPX_GENERIC_WAIT_NOTE
    */
    IMPORT_C void ShowWaitNoteL( TDesC& aText, TInt aCBAId,
        TBool aVisibilityDelayOff, MProgressDialogCallback* aCallback, TInt aResId = R_MPX_GENERIC_WAIT_NOTE );

    /**
     * Dismiss wait note
     */
    IMPORT_C void DismissWaitNoteL();

    /**
    * Handles displaying the error message for given error code
    * according to the media object provided
    *
    * @since S60 3.2.3
    * @param aError Error code
    * @param aMedia MPXMedia object
    * @param aFile Handle to file
    * @return KErrNone if no error, or else if a dialog is displayed will
    *         return the Button ID used to dismiss dialog.
    */
    IMPORT_C TInt HandleErrorL( TInt aError,
                                const CMPXMedia* aMedia=NULL,
                                RFile* aFile=NULL );

    /**
    * Adds given resource text as MSK to CBA.
    *
    * @since S60 3.2.3
    * @param aCba a button group container
    * @param aResourceId middle softkey label.
    * @param aCommandId command that should be performed when MSK
    *        is pressed.
    */
    IMPORT_C void SetMiddleSoftKeyLabelL(
        CEikButtonGroupContainer& aCba,
        TInt aResourceId,
        TInt aCommandId );

    /**
    * Removes current MSK label
    *
    * @since S60 3.2.3
    * @param aCba a button group container
    */
    IMPORT_C void RemoveMiddleSoftKeyLabel(
        CEikButtonGroupContainer& aCba );

    /**
    * Adds given resource icon as MSK to CBA.
    *
    * @since S60 3.2.3
    * @param aCba a button group container
    * @param aBitmap a bitmap
    * @param aMask a bitmap mask
    */
    IMPORT_C void SetMiddleSoftKeyIconL(
        CEikButtonGroupContainer& aCba,
        CFbsBitmap* aBitmap,
        CFbsBitmap* aMask );

    /**
    * Generate the next available title from the given title for the category.
    * The generated title is unique within the category regardless of the
    * media type within the category and its location.
    * e.g. c:\data\playlists\Playlist.m3u exists in the collection, the next
    * available title for the playlist category will be Playlist(01) regardless
    * if the title is going to be used for a playlist located in e:\data\playlists
    * or if it's a xml playlist file.
    *
    * @since S60 3.2.3
    * @param aCategory specifies the category for the title
    * @param aBaseTitle specifies the base title for new title generation
    * @return the next available title in the category in "BaseTitle(number)"
    *         format where number is the lowest available number.
    */
    IMPORT_C HBufC* GenerateTitleL(
        TMPXGeneralCategory aCategory,
        const TDesC& aBaseTitle );

    /**
    * Checks if Exit option should be hidden
    *
    * @since S60 3.2.3
    * @return ETrue if exit option should be hidden, EFalse otherwise
    */
    IMPORT_C TBool ExitOptionHiddenL();

    /**
    * Sets standalone mode process ID
    *
    * @since S60 3.2.3
    * @param aPId Process ID for standalone mode, 0 to reset
    * @return ETrue if successful, EFalse otherwise
    */
    IMPORT_C static TBool SetStandAloneModePId( TInt64 aPId );

    /**
    * Gets stand alone mode's process id
    *
    * @since S60 3.2.3
    * @return Stand alone mode's process ID, or 0 if not found
    */
    IMPORT_C static TInt64 StandAloneModePId();


    /**
    * Checks if the application with the provided group id is in foreground
    * This method is required because AppUi()->IsForeground() does not work
    * properly when the screen saver is active
    *
    * @since S60 3.2.3
    * @param aWindowGroupId application group identifier
    * @return ETrue if the application is in foreground, EFalse otherwise
    */
    IMPORT_C TBool IsForegroundApplication(TInt aWindowGroupId);

    /**
    * Get the Drive Number for the MMC card
    *
    * @since S60 3.2.3
    * @return Drive Number as defined in TDriveNumber or error code
    */
    IMPORT_C static TInt MMCDriveNumber();


    /**
     * Cancel all subsequent operations scheduled by CollectionUiHelper
     * Currently, this method is only used to cancel adding songs incrementally
     * to the playlist (user clicks on Cancel on the wait note)
     */
    IMPORT_C void CancelCollectionOperation();
    
                            
private:

    /**
    * C++ default constructor.
    *
    * @since S60 3.2.3
    * @param aCollectionUtility Collection utility to use for this helper
    */
    CMPXCommonUiHelper(MMPXCollectionUtility* aCollectionUtility);

    /**
    * By default Symbian 2nd phase constructor is private.
    */
    void ConstructL();

    /**
    * Check if memory card is present and writable.
    *
    * @since S60 3.2.3
    * @param aDrive If return is ETrue, aDrive contains the drive letter
    * @return ETrue if memory card is present and writable.
    */
    TBool IsMemoryCardWritable( TChar& aDrive );

    /**
    * Show playlist creation queries: memory selection and name query.
    *
    * @since S60 3.2.3
    * @param aPath Descriptor to receive the full path and
    *              name of the playlist file
    */
    TBool PlaylistCreationQueriesL( TDes& aPath );

    /**
    * Get next available playlist full pathname based on the information passed.
    *
    * @since S60 3.2.3
    * @param aBuf Buffer contains the file path and initial playlist name (optional).
    *             This buffer must be big enough to hold all texts.
    * @return KErrNone if everything ok.
    */
    TInt GetNextPlaylistNameL( TDes& aBuf );

    /**
    * Finds all medias in the specified category. Matching medias should
    * return the specified attributes
    *
    * @since S60 3.2.3
    * @param aAttrs attributes to return for the matching media(s)
    * @return matching media(s)
    */
    CMPXMedia* FindAllL(TMPXGeneralCategory aCategory, const TArray<TMPXAttribute>& aAttrs);

    /**
    * From MMPXCHelperObserver
    * Handles the completion of any collection helper event.
    *
    * @since S60 3.2.3
    * @param aOperation, operation completed
    * @param aErr. the error code
    * @param aArgument Argument returned from the operation
    */
    void HandleOperationCompleteL( TCHelperOperation aOperation,
                                   TInt aErr,
                                   void* aArgument );

    TBool PlaylistCreateNameExistL( TDes& aName, const TParseBase& aParse );
private:    // Data

    TInt                        iResourceOffset;   // must be freed
    CMPXDrmUiHelper*            iMpxDrmHelper; // owned
    MMPXCollectionUiHelper*     iCollectionUiHelper;
    MMPXCHelperObserver*        iAddObserver;
    CAknWaitDialog*             iWaitDialog;
    MMPXCollectionUtility*      iCollectionUtility; // not owned
    TInt                        iAppUiResourceOffset;

// Cover UI start
//#ifdef __COVER_DISPLAY
    TBool iCoverDisplay;
//#endif
// Cover UI end

    };

#endif  // C_CMPXCOMMONUIHELPER_H

// End of File
