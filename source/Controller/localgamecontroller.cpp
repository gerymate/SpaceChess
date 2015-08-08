// (C) Máté Gergely - gerymate@gmail.com
#include "localgamecontroller.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace Controller
{

LocalGameController::LocalGameController(shared_ptr<Core> theCore)
    : GameController{theCore}, playerController{theCore}
{
}

LocalGameController::~LocalGameController()
{    
}

void LocalGameController::mainLoop()
{
    while (core->getRenderer()->getWindow()->isOpen())
    {    
	handleSystemEvents();
	handleGameEvents();
	core->getRenderer()->update();
    }
    saveGame();
}

void LocalGameController::handleGameEvents()
{
    EventQueue* eventQueue = core->getEventQueue();
    while (!eventQueue->empty())
    {
	PointerToEvent event = eventQueue->front();
	eventQueue->pop();
	std::string sender = event->getSender();
	
	if (sender == "Board")
	{
	    playerController.handleSelection(event);
	}
    }
}

void LocalGameController::handleSystemEvents()
{
    sf::Event event;
    while (core->getRenderer()->getWindow()->pollEvent(event))
    {
	switch (event.type)
	{
	    case sf::Event::Closed:
		core->getRenderer()->getWindow()->close();
		break;
	    case sf::Event::MouseButtonPressed:
		{
		    sf::Vector2f mousePosition { sf::Mouse::getPosition(*(core->getRenderer()->getWindow())) };
		    core->getRenderer()->handleClick(mousePosition);
		}
		break;
	    case sf::Event::KeyReleased:
		switch (event.key.code)
		{
		    case sf::Keyboard::Key::PageDown:
			core->getRenderer()->zoomIn();
			break;
		    case sf::Keyboard::Key::PageUp:
			core->getRenderer()->zoomOut();
			break;
		    default:
			Log::that("Unhandled key pressed.");
			break;
		}
		break;
	    default:
		break;
	}
    }
}

void LocalGameController::setCursor(sf::Event event)
{
    sf::Vector2f position(event.mouseMove.x, event.mouseMove.y);    
    cursor = core->getRenderer()->setAndGetBoardCursorFromScreenPosition(position);
}

void LocalGameController::saveGame(string fileName)
{
    try 
    {
	ofstream outputStream {fileName};
	outputStream << *(core->getGame());
	outputStream.close();
    } catch (...) {
	std::cerr << "Error while saving the game to the file " << fileName << " !\n";
    }
}

}