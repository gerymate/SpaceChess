#ifndef FILEBASEDGAMECONTROLLER_H
#define FILEBASEDGAMECONTROLLER_H

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Model/gamev1.h"
#include "Model/gamestate.h"
#include "View/render2d.h"
#include "Controller/gamecontroller.h"

class FileBasedGameController : public GameController
{
    sf::RenderWindow* window;
    Model::GameV1 game;
    View::Render2D boardPainter;
    std::ifstream fileOfMoves;

    void initFileBasedGame();
    bool update(sf::Event event);
    
public:
    FileBasedGameController(sf::RenderWindow* theWindow);
    ~FileBasedGameController();
    void dispatchEvents() override;
};

#endif // FILEBASEDGAMECONTROLLER_H
