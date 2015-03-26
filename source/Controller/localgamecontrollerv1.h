#ifndef LOCALGAMECONTROLLER_H
#define LOCALGAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Model/gamev1.h"
#include "Model/gamestate.h"
#include "View/render2d.h"
#include "Controller/gamecontroller.h"

class LocalGameControllerV1 : public GameController
{
    sf::RenderWindow* window;
    Model::GameV1 game;
    View::Render2D renderer;
    Model::Coord cursor {-1, -1, -1};

    void initLocalGame();
    bool update(sf::Event event);
    void setCursor(sf::Event event);
    
public:
    LocalGameControllerV1(sf::RenderWindow* theWindow);
    virtual ~LocalGameControllerV1();
    void dispatchEvents() override;
};

#endif // LOCALGAMECONTROLLER_H
