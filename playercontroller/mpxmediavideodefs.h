/*
* Copyright (c) 2008 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:   Definitions for video media type*
*/


// Version : %version: 5 %




#ifndef __MPXMEDIAVIDEODEFS_H__
#define __MPXMEDIAVIDEODEFS_H__

#include <e32base.h>
#include <mpxattribute.h>

//
//  Content ID identifying video category of content provided
//  in the media object and associated attributes.
//

const TInt KMPXMediaIdVideo = 0x200159B0;

//
//  Attributes supported for KMPXMediaIdVideo
//
const TMPXAttributeData KMPXMediaVideoArtist              = { KMPXMediaIdVideo, 0x01 };
const TMPXAttributeData KMPXMediaVideoAudioEnabled        = { KMPXMediaIdVideo, 0x02 };
const TMPXAttributeData KMPXMediaVideoVideoEnabled        = { KMPXMediaIdVideo, 0x04 };
const TMPXAttributeData KMPXMediaVideoPlaybackMode        = { KMPXMediaIdVideo, 0x08 };
const TMPXAttributeData KMPXMediaVideoSeekable            = { KMPXMediaIdVideo, 0x10 };
const TMPXAttributeData KMPXMediaVideoPartialPlayback     = { KMPXMediaIdVideo, 0x20 };
const TMPXAttributeData KMPXMediaVideoHeight              = { KMPXMediaIdVideo, 0x40 };
const TMPXAttributeData KMPXMediaVideoWidth               = { KMPXMediaIdVideo, 0x80 };
const TMPXAttributeData KMPXMediaVideoBitRate             = { KMPXMediaIdVideo, 0x100 };
const TMPXAttributeData KMPXMediaVideoDrmProtected        = { KMPXMediaIdVideo, 0x200 };
const TMPXAttributeData KMPXMediaVideoPausableStream      = { KMPXMediaIdVideo, 0x400 };
const TMPXAttributeData KMPXMediaFourCCCode               = { KMPXMediaIdVideo, 0x800 };
const TMPXAttributeData KMPXMediaVideoDescription         = { KMPXMediaIdVideo, 0x1000 };
const TMPXAttributeData KMPXMediaVideoLocation            = { KMPXMediaIdVideo, 0x2000 };
const TMPXAttributeData KMPXMediaVideoCopyright           = { KMPXMediaIdVideo, 0x4000 };
const TMPXAttributeData KMPXMediaVideoLanguage            = { KMPXMediaIdVideo, 0x8000 };
const TMPXAttributeData KMPXMediaVideoKeywords            = { KMPXMediaIdVideo, 0x10000 };
const TMPXAttributeData KMPXMediaVideoCreated             = { KMPXMediaIdVideo, 0x20000 };
const TMPXAttributeData KMPXMediaVideoLastModified        = { KMPXMediaIdVideo, 0x40000 };

const TMPXAttributeData KMPXMediaVideoAll                 = { KMPXMediaIdVideo, 0xffffffff };

#endif // __MPXMEDIAVIDEODEFS_H__
