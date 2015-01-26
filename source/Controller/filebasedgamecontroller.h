#ifndef FILEBASEDGAMECONTROLLER_H
#define FILEBASEDGAMECONTROLLER_H

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Model/game.h"
#include "Model/gamestate.h"
#include "View/boardpainter2d.h"
#include "Controller/gamecontroller.h"

class FileBasedGameController : public GameController
{
    sf::RenderWindow* window;
    Model::Game game;
    View::BoardPainter2D boardPainter;
    std::ifstream fileOfMoves;

    void initFileBasedGame();
    bool update(sf::Event event);
    
public:
    FileBasedGameController(sf::RenderWindow* theWindow);
    ~FileBasedGameController();
    void dispatchEvents();
};

#endif // FILEBASEDGAMECONTROLLER_H
