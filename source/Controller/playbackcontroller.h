// (C) Máté Gergely - gerymate@gmail.com
#ifndef PLAYBACKCONTROLLER_H
#define PLAYBACKCONTROLLER_H

#include <SFML/Window.hpp>
#include "common.h"
#include "gamecontroller.h"

namespace Controller
{
    
class PlaybackController : public GameController
{
    std::string helpText;

    void handleSystemEvents();
    void handleGameEvents();
    void loadGame(const std::string& fileName);
    void emitStepForwardEvent();
    void emitStepBackwardEvent();
    
public:
    PlaybackController(std::shared_ptr<Core> theCore, 
		       const std::string& fileName);
    virtual ~PlaybackController();
    void mainLoop();
};

}
#endif // PLAYBACKCONTROLLER_H
