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
* Description:  MPX internal CenRep keys.
*
*/



#ifndef MPXINTERNALCRKEYS_H
#define MPXINTERNALCRKEYS_H


// Music Player Application Features Uid
const TUid KCRUidMPXMPFeatures = { 0x101FFCD0 };


// Local variation property value
const TUint32 KMPXMPLocalVariation   = 0x00000001;

// Feature flag definitions for local variation


// Feature to enable changing ringing tone for all profiles. When disabled
// ringing tone is changed only for the active profile.
#define KMPXChangeRTForAll      0x0001

// Feature to enable marquee (scrolling) text for artist name label in
// Music Player. When enabled and if the artist name is too long to fit into
// space reserved for it, the label starts scrolling. Scrolling is associated
// to player state, when playing is started the label starts scrolling and if
// the playing is stopped the scrolling stops, too.
#define KMPXMarqueeArtistName   0x0002

// Feature to enable Rocker Key Mapping support.
#define KMPXRockerMappingSupport 0x0004

// Feature to disable podcasting from music player
// +128 to disable podcasting
#define KMPXDisablePodcastingOption 0x0008

// Feature to enable RAM disk database copying
#define KMPXEnableRAMDisk 0x00f0

#define KMAXAllowedDiskSpaceToCopy 0x9
// Feature to enable Go To MusicShop option in option menus.
#define KMPXEnableGoToMusicShopOption 0x0010

// Feature to enable Find In MusicShop option in option menus
#define KMPXEnableFindInMusicShopOption 0x0020

// Feature to enable exit option in option menus.
#define KMPXEnableExitOption 0x0040

// Feature to open Music Player in Artists & Album collection view.
#define KMPXStartMusicPlayerinArtistsandAlbums 0x0080

// Speed Scroll settings feature Uid
const TUid KCRUidMPXMPExtendedFeatures = { 0x101FFCD1 };

// Speed scrolling settings
// setting for buffer time from idle to first speed
const TUint32 KMPXMPSpeedScrollFirBuffTime    = 0x00000001;
// setting for buffer time from first speed to second speed
const TUint32 KMPXMPSpeedScrollSecBuffTime    = 0x00000002;
// value for first speed
const TUint32 KMPXMPSpeedScrollFirSpeed       = 0x00000003;
// value for second speed
const TUint32 KMPXMPSpeedScrollSecSpeed       = 0x00000004;

#endif  // MPXINTERNALCRKEYS_H

// End of file
