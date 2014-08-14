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
* Description:  MPX media key handler interface definition
*
*/



#ifndef C_MMPXMEDIAKEYHANDLER_H
#define C_MMPXMEDIAKEYHANDLER_H


// INCLUDES
#include <e32base.h>
#include <mpxmediakeyhandlerobserver.h>
#include <mpxmediakeyhandlerdefs.h>

// DATA TYPES
typedef TInt TMPXMediaKeyPopupFlags;

// CONSTANTS
/**
 * Constants for media key feature flags
 */
#define EDisplayVolumePopup 0x0001
#define EDisplayMediaPopup  0x0002

// CLASS DECLARATION

/**
 *  MPX media key handler interface.
 *
 *  @lib mpxmediakeyhandler.lib
 *  @since S60 3.2.3
 */
NONSHARABLE_CLASS( MMPXMediaKeyHandler )
    {
public:

    /**
     * Two-phased constructor.
     *
     * @since S60 5.0
     * @param aFlags Flags for creating popups.
     * @param aObserver Media key command observer
     * @return Pointer to newly created object.
     */
    IMPORT_C static MMPXMediaKeyHandler* NewL(
        TMPXMediaKeyPopupFlags aFlags,
        MMPXMediaKeyHandlerObserver* aObserver );

    /**
     * Destructor.
     */
    virtual ~MMPXMediaKeyHandler();

    /**
     * Show playback popup
     *
     * @since S60 3.2.3
     * @param aMode Playback popup behaviour mode
     */
    virtual void ShowPlaybackPopupL( TMPXPlaybackPopupModes aMode ) = 0;

    /**
     * Show Volume popup
     *
     * @since S60 5.0
     */
    virtual void ShowVolumePopupL() = 0;

    /**
     * Dismiss notifier popup.
     *
     * @since S60 3.2.3
     * @param aFlags Popup flag to determine which popup(s) should
     *               be dismissed.
     */
    virtual void DismissNotifier( TMPXMediaKeyPopupFlags aFlags ) = 0;


    /**
     * Enable or disable Media Key behavior
     * @since S60 3.2.3
     * @param aEnable, ETrue, media keys are sent to observers
     *                 EFalse, media keys are ignored
     */
    virtual void SetEnableMediaKeys( TBool aEnable ) = 0;
    
    /**
     * Gets called when orientation change begins
     */    
    virtual void NotifyOrientationChangeBegin() = 0;
    };

#endif  // C_MMPXMEDIAKEYHANDLER_H

// End of File
