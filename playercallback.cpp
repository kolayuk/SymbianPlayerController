#include "playercallback.h"

playerCallBack::playerCallBack()
{
}

void playerCallBack::PlayerStateChanged(TMPXPlaybackState aState)
{
    // user (or app) paused/stopped/etc
}

void playerCallBack::TrackInfoChanged(const TDesC &aTitle, const TDesC &aArtist)
{
    // another file playing now, check getUtility()->Uri() for file path
}

void playerCallBack::PlaybackPositionChanged(TInt aPosition)
{
    // aPosition in milliseconds
}

void playerCallBack::AlbumArtChanged(CFbsBitmap *aBitmap)
{
    // never called, you need a lot of headers and libs from PDK to get album arts support
}

void playerCallBack::Opening()
{
}

void playerCallBack::PlaylisIsEmpty()
{
}
