#ifndef PLAYBACKCONTROLLER_H
#define PLAYBACKCONTROLLER_H

#include "common.h"
#include "gamecontroller.h"
#include <SFML/Graphics.hpp>
#include "Model/game.h"
#include "Model/gamestate.h"
#include "View/render2d.h"
#include "event.h"
#include "Controller/playercontroller.h"
#include "Model/position.h"

namespace Controller
{
    
class PlaybackController : public GameController
{
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
