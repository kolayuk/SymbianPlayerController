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
* Description:  Class declarations of CMPXLbxExtendedFeatures
*
*/


#ifndef MPXLBXEXTENDEDFEATURES_H
#define MPXLBXEXTENDEDFEATURES_H

// INCLUDES
#include <mdaaudiotoneplayer.h>
#include <mpxcollectionobserver.h>

// FORWARD DECLARATIONS
class CEikTextListBox;
class CAknNavigationDecorator;
class CAknNaviLabel;
class CAknNavigationControlContainer;
class MMPXCollectionUtility;


// CLASS DECLARATION

/**
*  CMPXLbxExtendedFeatures class
*
*  Extended features for listbox views
*/
NONSHARABLE_CLASS( CMPXLbxExtendedFeatures ) : public CBase,
                                               public MMdaAudioToneObserver,
                                               public MMPXCollectionObserver
    {
public:

    enum TMPXKeyStatus
        {
        EMPXKeyOther = 0,
        EMPXKeyUp,
        EMPXKeyDown
        };

    enum TMPXScrollingStates
        {
        EMPXScrollingIdle = 0,
        EMPXScrolling1stBufferTime,
        EMPXScrolling1stSpeed,
        EMPXScrolling2ndBufferTime,
        EMPXScrolling2ndSpeed
        };

public: // Constructors and destructor

    /**
    * Symbian OS two-phased constructor.
    * @since S60 3.2.3
    * @param aLbx The handle to the list box view
    * @param aEnableSetIndex ETrue to enable set index to collection server
    *                        everytime the list is browsed
    */
    IMPORT_C static CMPXLbxExtendedFeatures* NewL(
        CEikTextListBox* aLbx,
        TBool aEnableSetIndex = ETrue );

    /**
    * C++ default destructor.
    * @since S60 3.2.3
    */
    IMPORT_C virtual ~CMPXLbxExtendedFeatures();

private:

    /**
    * C++ default constructor.
    * @since S60 3.2.3
    * @param aLbx The handle to the list box view
    * @param aEnableSetIndex ETrue to enable set index to collection server
    *                        everytime the list is browsed
    */
    CMPXLbxExtendedFeatures(
        CEikTextListBox* aLbx,
        TBool aEnableSetIndex );

    /**
    * Symbian OS default constructor.
    * @since S60 3.2.3
    */
    void ConstructL();

public:     // New functions

    /**
    * Handle listbox key events
    * @since S60 3.2.3
    * @param aKeyEvent Key event
    * @param aType Type of key event
    */
    IMPORT_C TKeyResponse HandleLbxKeyEventL( const TKeyEvent& aKeyEvent, TEventCode aType );

    /**
    * Enable or disable speed scrolling
    * @since S60 3.2.3
    * @param isEnable ETrue if speed scrolling is desired.  EFalse otherwise.
    */
    IMPORT_C void EnableSpeedScrollL( TBool isEnable );

    /**
    * Enable or disable navipane labeling
    * @since S60 3.2.3
    * @param aNaviEnable ETrue if labeling is desired.  EFalse otherwise.
    */
    IMPORT_C void SpeedNaviUpdating( TBool aNaviEnable );

    /**
    * Reset everything to default.
    * @since S60 3.2.3
    */
    void Reset();

    /**
    * Enable or disable auto loop
    * @since S60 3.2.3
    * @param isEnable ETrue if auto loop is desired.  EFalse otherwise.
    */
    void EnableAutoLoop( TBool isEnable );

    /**
    * Timer callback, this is called on each timer event.
    * @since S60 3.2.3
    * @param aPtr pointer to the object for type casting (given in Timer creation).
    * @return ETrue after successful timer cycle.
    */
    static TInt TimerCallBack( TAny* aPtr );

private:    // New functions

    /**
    * Construct and start buffer timer.
    * @since S60 3.2.3
    */
    void StartTimerL();

    /**
    * Stop and destroy timer.
    * @since S60 3.2.3
    */
    void StopTimer();

    /**
    * Change scrolling status, called by TimerCallBack().
    * @since S60 3.2.3
    */
    void BufferTimerHandler();

    /**
    * Update the scrolling speed
    * @since S60 3.2.3
    */
    void UpdateScrollingSpeed( TMPXKeyStatus aKeyStatus );

    /**
    * Check if boundary is reached.
    * @since S60 3.2.3
    * @param aKeyStatus current key status.
    * @return ETrue is boundary is reahced.  Otherwise EFalse.
    */
    TBool CheckBoundaryCases( TMPXKeyStatus aKeyStatus );

    /**
    * Get info (ie. scrolling speed) from the cenrep
    * @since S60 3.2.3
    */
    void GetInfoFromCenRepL();

    /**
    * Updates the Navi pane with the appropriate speed text
    * @since S60 3.2.3
    */
    void SetNaviSpeedTextL( TBool boundaryReached );

    /**
    * Handles key event down
    * @since S60 3.2.3
    * @param aKeyEvent Key event
    */
    TKeyResponse HandleEventKeyDownL( const TKeyEvent& aKeyEvent );

    /**
    * Handles key event up
    * @since S60 3.2.3
    * @param aKeyEvent Key event
    */
    TKeyResponse HandleEventKeyUpL( const TKeyEvent& aKeyEvent );

    /**
    * Enables/Disables Keysound
    * @since S60 3.2.3
    * @param aEnable ETrue to enable key sound, EFalse to disable
    */
    void EnableKeySoundL( TBool aEnable );

    /**
    * Send an async command to the collection to update the index
    * @since S60 3.2.3
    * @param aIndex index to set
    * @param aForceSet ETrue if speed scrolling checking should be bypassed
    */
    void SetIndexToCollectionL( TInt aIndex, TBool aForceSet = EFalse );

    /**
    * Handle collection message
    * @since S60 3.2.3
    * @param aMessage collection message
    * @param aError Error code
    */
    void DoHandleCollectionMessageL( CMPXMessage* aMessage, TInt aError );

// from base class MMdaAudioToneObserver
    /**
    * From MMdaAudioToneObserver. Called after tone has been initialized.
    * @since S60 3.2.3
    * @param aError Error code
    */
    void MatoPrepareComplete(TInt aError);

    /**
    * From MMdaAudioToneObserver. Called after tone has been played.
    * @since S60 3.2.3
    * @param aError Error code
    */
    void MatoPlayComplete(TInt aError);

    /**
    * From MMPXCollectionObserver
    * Handle collection message.
    * @since S60 3.2.3
    * @param aMessage Collection message
    * @param aErr system error code.
    */
    void HandleCollectionMessage(
        CMPXMessage* aMessage, TInt aError );

    /**
    * From MMPXCollectionObserver
    * Handles the collection entries being opened. Typically called
    * when client has Open()'d a folder
    *
    * @since S60 3.2.3
    * @param aEntries collection entries opened
    * @param aIndex focused entry
    * @param aComplete ETrue no more entries. EFalse more entries
    *                  expected
    * @param aError error code
    */
    void HandleOpenL(
        const CMPXMedia& aEntries,
        TInt aIndex,
        TBool aComplete,
        TInt aError );

    /**
    * From MMPXCollectionObserver
    * Handles the collection entries being opened. Typically called
    * when client has Open()'d an item. Client typically responds by
    * 'playing' the item
    *
    * @since S60 3.2.3
    * @param aPlaylist collection path to item
    * @param aError error code
    */
    void HandleOpenL(
        const CMPXCollectionPlaylist& aPlaylist,
        TInt aError );

    /**
    * From MMPXCollectionObserver
    * Handle media properties
    *
    * @since S60 3.2.3
    * @param aMedia media
    * @param aError error code
    */
    void HandleCollectionMediaL(
        const CMPXMedia& aMedia,
        TInt aError );

    private:    // Data

    RWsSession              iWsSession;
    CPeriodic*              iTimer;
    CEikTextListBox*        iLbx;
    TMPXKeyStatus           iKeyStatus;
    TMPXScrollingStates     iScrollingState;
    CMdaAudioToneUtility*   iToneUtility;
    MMPXCollectionUtility*  iCollectionUtility;

    // Contain info from shared data
    TInt                    iFirstBufferTime;
    TInt                    iSecondBufferTime;
    TInt                    iFirstSpeed;
    TInt                    iSecondSpeed;
    TInt                    iIndexCount; // counter for speed scolling set index check
    TInt                    iResourceOffset;   // must be freed

    TBool                   iSpeedScrollEnabled;
    TBool                   iAutoLoopEnabled;
    TBool                   iNaviEnabled;
    TBool                   iKeysoundEnabled;
    TBool                   iSkipEvent;
    TBool                   iFirstKeyEvent;
    TBool                   iSkipPlaying;
    TBool                   iEnableSetIndex;

    //FOR NAVI PANE
    CAknNavigationDecorator*        iNaviDecorator;
    CAknNaviLabel*                  iNaviLabel;
    CAknNavigationControlContainer* iNaviPane;
    };

#endif  // MPXLBXEXTENDEDFEATURES_H

// End of File
