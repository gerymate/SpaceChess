#include "gamecontroller.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace Controller
{

GameController::GameController(sf::RenderWindow* theWindow) 
    : window{theWindow}, renderer{theWindow, &game, &eventQueue}
{
    initLocalGame();
}

void GameController::initLocalGame()
{
}


GameController::~GameController()
{

}

void GameController::mainLoop()
{
    while (window->isOpen())
    {    
	handleSystemEvents();
	handleGameEvents();
	renderer.update();
    }
}

void GameController::handleGameEvents()
{

}

void GameController::handleSystemEvents()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
	switch (event.type)
	{
	    case sf::Event::Closed:
		window->close();
		break;
	    case sf::Event::MouseButtonPressed:
		{
		    sf::Vector2f mousePosition { sf::Mouse::getPosition(*window) };
		    renderer.handleClick(mousePosition);
		}
		break;
	    default:
		break;
	}
    }
}

void GameController::setCursor(sf::Event event)
{
    sf::Vector2f position(event.mouseMove.x, event.mouseMove.y);    
    cursor = renderer.setAndGetCoordByPosition(position);
}


Model::GameState GameController::loadBoardFromFile()
{
    // load file "initial.board"
    const string fileNameOfBoard("initial.board");
    ifstream boardFile(fileNameOfBoard);
    if (!boardFile.is_open()) {
        cerr << "Error, file not fould: " << fileNameOfBoard << endl;
        exit(1);
    }

    Model::GameState board;
    boardFile >> board;
    boardFile.close();

    return board;
}

}