#include <QtCore/QCoreApplication>
#include "playercontroller/aiplayerpluginengine.h"
#include "playercontroller/mpxplaybackutility.h"
#include "playercallback.h"
#include "mpxplaybackcommanddefs.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //we will get player events here
    playerCallBack* cb=new playerCallBack();
    //create controller instance for video player
    //you can pass CAiPlayerPluginEngine::EAudioPlayer to control audio player
    CAiPlayerPluginEngine* playerController=CAiPlayerPluginEngine::NewL(*cb,CAiPlayerPluginEngine::EVideoPlayer);
    //set volume for it
    // check TMPXPlaybackProperty at mpxplaybackframeworkdefs.h for more options
    playerController->getUtility()->SetL(EPbPropertyVolume,99);
    // let's pause playback
    //check TMPXPlaybackCommand at mpxplaybackcommanddefs.h for more options
    playerController->getUtility()->CommandL(EPbCmdPause);
    User::After(1000000); // just wait
    delete playerController;
    return 0;
}
