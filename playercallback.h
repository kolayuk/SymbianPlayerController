#ifndef PLAYERCALLBACK_H
#define PLAYERCALLBACK_H

#include <playercontroller/aiplayerpluginengineobserver.h>

class playerCallBack: public MAiPlayerPluginEngineObserver
{
public:
    playerCallBack();
    void PlayerStateChanged( TMPXPlaybackState aState );
    void TrackInfoChanged( const TDesC& aTitle, const TDesC& aArtist );
    void PlaybackPositionChanged( TInt aPosition );
    void AlbumArtChanged( CFbsBitmap* aBitmap );
    void Opening();
    void PlaylisIsEmpty();

};

#endif // PLAYERCALLBACK_H
