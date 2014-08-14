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
* Description:  MPXMusicPlayer constants
*
*/



#ifndef MPXCONSTANTS_H
#define MPXCONSTANTS_H


// INCLUDES
#include "mpxmusicplayer.hrh"


// CONSTANTS
// MusicPlayer application UID
const TUid KAppUidMusicPlayerX = {KMusicPlayerAppUidConstant};

// Host application UIDs in embedded mode
#define KMPXMessagingUid  0x100058C5
#define KMPXMmsViewerUid  0x100058DF
#define KMPXMmsEditorUid  0x100058DE
#define KMPXMailViewerUid 0x101F4CE4
#define KMPXMailEditorUid 0x101F4CD6
#define KMPXBrowserUid    0x10008D39
#define KMPXBrowserUid2   0x1020724D
#define KMPXMusicShopUid  0x101F8839

// Uid for Podcast Collection Plugin
const TUid KMPXUidPodcastDBPlugin = { 0x101FFC3C };

// DATA TYPES

// MPX Music Player start up parameters (dochandler), the order of enums can't 
// be changed.
enum TMPXLaunchMode
    {
    // Player is started in playing state
    EMPXLaunchModePlaying,

    // Player is started in stopped state
    EMPXLaunchModeStopped,

    // Player is started to play a preview
    // clip embedded in the audio file
    EMPXLaunchModePlayPreview,

    // Not in embedded mode or unknown status
    EMPXLaunchModeUnknown,

    // A single track was opened in embedded mode
    EMPXLaunchModeTrack,

    // A playlist was opened in embedded mode
    EMPXLaunchModePlaylist,

    // A temporary playlist was opened by
    // marking several tracks in Gallery
    EMPXLaunchModeTempPlaylist
    };

// Trigger codes for MPX music player view transitions
enum TTransitionType
    {
    EMPXTranstionNotDefined = 0,
    EMPXTranstionToRight = 1001,
    EMPXTranstionToLeft = 1002       
    };

// ERROR CODES

// Error code to note that the rights on a DRM file are about to expire
// so the proper warning message can be displayed.
const TInt KMPXRightsAboutToExpire  = -40000;     

// Error code to indicate that all tracks in a playlist are invalid so the
// proper error message can be displayed.
const TInt KMPXAllTracksInvalid     = -40001;

// Error code to indicate that playback not allowed during video call
const TInt KMPXErrorVideoCall       = -40002;

// Error code to indicate expired DRM rights
const TInt KMPXErrorExpiredRights       = -40003;


#endif  // MPXCONSTANTS_H   
            
// End of File
