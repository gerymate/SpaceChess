#ifndef LOCALGAMECONTROLLER_H
#define LOCALGAMECONTROLLER_H

#include "common.h"
#include "gamecontroller.h"

namespace Controller
{
    
class LocalGameController : public GameController
{
protected:
    PlayerController playerController;
    Model::Position cursor {Model::Position::Invalid};
    
    virtual void setCursor(sf::Event event);
    virtual void handleSystemEvents() override;
    virtual void handleGameEvents() override;
    void saveGame(std::string fileName = "lastspacechessgame.txt");
    
public:
    LocalGameController(sf::RenderWindow* theWindow);
    virtual ~LocalGameController();
    virtual void mainLoop();
};

}
#endif // LOCALGAMECONTROLLER_H
