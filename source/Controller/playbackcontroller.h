// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
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
    PlaybackController(sf::RenderWindow* theWindow, 
		       const std::string& fileName);
    virtual ~PlaybackController();
    void mainLoop();
};

}
#endif // PLAYBACKCONTROLLER_H
