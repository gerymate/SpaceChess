// (C) Máté Gergely - gerymate@gmail.com
#ifndef LOCALGAMECONTROLLER_H
#define LOCALGAMECONTROLLER_H

#include "common.h"
#include "gamecontroller.h"
#include "playercontroller.h"

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
    LocalGameController(std::shared_ptr<Core> theCore);
    virtual ~LocalGameController();
    virtual void mainLoop();
};

}
#endif // LOCALGAMECONTROLLER_H
