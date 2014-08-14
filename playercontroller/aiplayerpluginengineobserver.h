/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
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


#ifndef M_AIPLAYERPLUGINENGINEOBSERVER_H
#define M_AIPLAYERPLUGINENGINEOBSERVER_H

#include <e32std.h>
#include <mpxplaybackframeworkdefs.h>
class CFbsBitmap;

/**
 *  Observer interface to be implemented by a client of AiPlayerPluginEngine.
 *
 *  @lib aiplayerplugin2.lib
 *  @since S60 5.0
 */
class MAiPlayerPluginEngineObserver
    {
public:

    /**
     * Called when active player instance's state changes
     *
     * @since S60 5.0
     * @param aState Active player state
     * @see TMPlayerState
     */
    virtual void PlayerStateChanged( TMPXPlaybackState aState ) = 0;

    /**
     * Called when track info changes (i.e. track changes or current track's
     * info is updated) in the active player instance.
     *
     * @since S60 5.0
     * @param aTitle Current track's title.
     * @param aArtist Current track's artist.
     */
    virtual void TrackInfoChanged( const TDesC& aTitle, 
            const TDesC& aArtist ) = 0;

    /**
     * Called each second during playback.
     *
     * @since S60 5.0
     * @param aPosition Current playback position in seconds.
     */
    virtual void PlaybackPositionChanged( TInt aPosition ) = 0;

    /**
     * Called when album art is ready or when there is no album art.
     *
     * @since S60 5.0
     * @param aBitmap the new album art.
     */
    virtual void AlbumArtChanged( CFbsBitmap* aBitmap ) = 0;
    
    /**
     * Called When there is an ongoing operation.
     *
     * @since S60 5.0
     */
    virtual void Opening() = 0;
    
    /**
     * Called when to indicate that the playlist changed and it is empty.
     *
     * @since S60 5.0
     * @param aBitmap the new album art.
     */
    virtual void PlaylisIsEmpty() = 0;

    };


#endif // ?M_AIPLAYERPLUGINENGINEOBSERVER_H
