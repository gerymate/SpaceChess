#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Model/game.h"
#include "Model/gamestate.h"
#include "View/boardpainter2d.h"

class GameController
{
    sf::RenderWindow* window;
    Model::Game game;
    View::BoardPainter2D boardPainter;
    std::ifstream fileOfMoves;

    void initFileBasedGame();
    Model::GameState loadBoardFromFile();

public:
    GameController(sf::RenderWindow* theWindow);
    ~GameController();
    bool update(sf::Event event);
};

#endif // GAMECONTROLLER_H
