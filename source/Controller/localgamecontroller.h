#ifndef LOCALGAMECONTROLLER_H
#define LOCALGAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Model/game.h"
#include "Model/gamestate.h"
#include "View/boardpainter2d.h"
#include "Controller/gamecontroller.h"

class LocalGameController : public GameController
{
    sf::RenderWindow* window;
    Model::Game game;
    View::BoardPainter2D boardPainter;
    Model::Coord cursor;

    void initLocalGame();
    bool update(sf::Event event);
    void setCursor(sf::Event event);
    
public:
    LocalGameController(sf::RenderWindow* theWindow);
    ~LocalGameController();
    virtual void dispatchEvents();
};

#endif // LOCALGAMECONTROLLER_H
