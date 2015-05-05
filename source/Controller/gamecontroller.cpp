#include "gamecontroller.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace Controller
{

GameController::GameController(sf::RenderWindow* theWindow) 
    : window{theWindow}, renderer{theWindow, &game, &eventQueue}, playerController{&game, &renderer}
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
    saveGame();
}

void GameController::handleGameEvents()
{
    while (!eventQueue.empty())
    {
	PointerToEvent event = eventQueue.front();
	eventQueue.pop();
	std::string sender = event->getSender();
	
	if (sender == "Board")
	{
	    playerController.handleSelection(event);
	}
    }
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
    cursor = renderer.setAndGetBoardCursorFromScreenPosition(position);
}

void GameController::saveGame(string fileName)
{
    try 
    {
	ofstream outputStream {fileName};
	outputStream << game;
	outputStream.close();
    } catch (...) {
	std::cerr << "Error while saving the game to the file " << fileName << " !\n";
    }
}

}