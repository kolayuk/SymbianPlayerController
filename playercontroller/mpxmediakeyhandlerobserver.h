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
* Description:  MPX media key command observer interface definition
*
*/



#ifndef C_MMPXMEDIAKEYHANDLEROBSERVER_H
#define C_MMPXMEDIAKEYHANDLEROBSERVER_H


// INCLUDES
#include <e32base.h>
#include <mpxplaybackcommanddefs.h>

// CLASS DECLARATION

/**
 *  MPX Media Key Handler command observer.
 *
 *  @lib mpxmediakeyhandler.lib
 *  @since S60 5.0
 */
NONSHARABLE_CLASS( MMPXMediaKeyHandlerObserver )
    {
public:

    /**
     * Handle media key commands.
     *
     * @since 5.0
     * @param aCommand Command to be handled.
     * @param aData data for the specific command
     */
    virtual void HandleMediaKeyCommand(
        const TMPXPlaybackCommand aCommand,
        const TInt aData ) = 0;
    };

#endif  // C_MMPXMEDIAKEYHANDLEROBSERVER_H

// End of File
