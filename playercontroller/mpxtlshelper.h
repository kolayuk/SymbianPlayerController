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
* Description:  MPX TLS helper implementation
*
*/



#ifndef C_MPXTLSHELPER_H
#define C_MPXTLSHELPER_H


// INCLUDES
#include <e32base.h>
#include <mpxconstants.h>


// DATA TYPES

/**
 * Structure used to store information in TLS.
 */
NONSHARABLE_STRUCT( TMPXTlsStruct )
    {
    /**
     * Host application UID. Used in embedded mode.
     */
    TUid iHostUid;

    /**
     * Flag to indicate save is allowed. Used in embedded mode.
     */
    TBool iNeedSave;

    /**
     * Flag to indicate move is allowed. Used in embedded mode.
     */
    TBool iAllowMove;

    /**
     * Player init mode. Used in embedded mode.
     */
    TMPXLaunchMode iLaunchMode;

    /**
     * Usage count.
     */
    TInt useCount;

    /**
     * File Name of the saved clip
     */
    TFileName iFilePath;
    };


// CLASS DECLARATION

/**
 *  MPX TLS Helper.
 *
 *  @lib mpxcommonui.lib
 *  @since S60 v3.2.3
 */
NONSHARABLE_CLASS( MPXTlsHelper )
    {
public:

    /**
     * Initialize TLS for storing application information.
     *
     * @since S60 v3.2.3
     */
    IMPORT_C static void InitializeL();

    /**
     * Uninitialize TLS data storage. Must be called
     * before exiting application to unload resources.
     *
     * @since S60 v3.2.3
     */
    IMPORT_C static void Uninitialize();

    /**
     * Store host application UID to TLS.
     *
     * @since S60 v3.2.3
     * @param aUid Host application UIDs
     */
    IMPORT_C static void SetHostUidL( const TUid& aUid );

    /**
     * Fetch host application UID from TLS.
     *
     * @since S60 v3.2.3
     * @return Host application UID if application is in embedded mode
     */
    IMPORT_C static TUid HostUid();

    /**
     * Set 'need save' flag. If the flag is set,
     * user is asked to save the track when exiting embedded mode.
     *
     * @since S60 v3.2.3
     * @param aNeedSave ETrue if save query should be shown on exit
     */
    IMPORT_C static void SetNeedSave( TBool aNeedSave );

    /**
     * Get 'need save' flag. If the flag is set,
     * user is asked to save the track when exiting embedded mode.
     *
     * @since S60 v3.2.3
     * @return ETrue If save query should be shown on exit
     */
    IMPORT_C static TBool NeedSave();

    /**
     * Sets Allow Move flag.
     *
     * @since S60 v3.2.3
     * @param aAllowMove ETrue if the clip should be moved instead of copy
     */
    IMPORT_C static void SetAllowMove( TBool aAllowMove );

    /**
     * Gets Allow Move flag.
     *
     * @since S60 v3.2.3
     * @return ETrue if the clip should be moved instead of copy
     */
    IMPORT_C static TBool AllowMove();

    /**
     * Set launch mode.
     *
     * @since S60 v3.2.3
     * @param aMode Launch mode in embedded mode, see TMPXLaunchMode
     */
    IMPORT_C static void SetLaunchModeL( TMPXLaunchMode aMode );

    /**
     * Get launch mode.
     *
     * @since S60 v3.2.3
     * @return Launch mode in embedded mode, see TMPXLaunchMode
     */
    IMPORT_C static TMPXLaunchMode LaunchMode();

    /**
     * Get the full path of saved file name.
     *
     * @since S60 v3.2.3
     * @return path to saved clip
     */
    IMPORT_C static TFileName FilePath();

    /**
     * Set the full path of saved file name.
     *
     * @since S60 v3.2.3
     * @param aFilePath
     */
    IMPORT_C static void SetFilePath( const TDesC& aFilePath );
    };

#endif  // C_MPXTLSHELPER_H

// End of File
