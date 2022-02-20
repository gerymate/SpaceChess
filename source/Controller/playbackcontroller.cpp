// (C) Máté Gergely - gerymate@gmail.com
#include "playbackcontroller.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace Controller
{

PlaybackController::PlaybackController(std::shared_ptr<Core> theCore, const std::string& fileName)
    : GameController(theCore)
{
    core->getRenderer()->setLocalPlayers(Model::Player::Nobody);
    helpText = std::string{"Playback mode: left click for previous move, right click for next."};
    core->getRenderer()->setMessage(helpText);
    loadGame(fileName);
}

PlaybackController::~PlaybackController()
{
}

void PlaybackController::mainLoop()
{
    while (core->getRenderer()->getWindow()->isOpen())
    {    
	handleSystemEvents();
	handleGameEvents();
	core->getRenderer()->update();
    }
}

void PlaybackController::loadGame(const std::string& fileName)
{
    try {
	std::ifstream inputFile {fileName};
	if (! inputFile.is_open())
	{
	    std::cerr << "Error during opening file " << fileName << " !\nMaybe in a wrong directory?\n";
	    exit(1);	    
	}
	inputFile >> *(core->getGame());
	inputFile.close();
    } catch (std::exception& e) {
	std::cerr << e.what() << "\n";
	exit(1);
    }
}

void PlaybackController::handleSystemEvents()
{       
    sf::Event event;
    sf::Window* window { core->getRenderer()->getWindow() };
    while (window->pollEvent(event))
    {
	switch (event.type)
	{
	    case sf::Event::Closed:
		window->close();
		break;
	    case sf::Event::MouseButtonPressed:
		{
		    if (event.mouseButton.button == sf::Mouse::Button::Left)
		    {
			emitStepBackwardEvent();
		    }
		    if (event.mouseButton.button == sf::Mouse::Button::Right)
		    {
			emitStepForwardEvent();
		    }		    
		}
		break;
	    default:
		break;
	}
    }
}

void PlaybackController::emitStepForwardEvent()
{
    std::string sender { "Controller" };
    std::string message { "Forward" };
    std::string params { "" };
    PointerToEvent event {new Event {sender, message, params} };
    core->getEventQueue()->push(event);
}

void PlaybackController::emitStepBackwardEvent()
{
    std::string sender { "Controller" };
    std::string message { "Backward" };
    std::string params { "" };
    PointerToEvent event {new Event {sender, message, params} };
    core->getEventQueue()->push(event);
}

void PlaybackController::handleGameEvents()
{
    EventQueue& eventQueue { *(core->getEventQueue()) };
    while (!eventQueue.empty())
    {
	PointerToEvent event = eventQueue.front();
	eventQueue.pop();
	std::string sender = event->getSender();
	std::string message = event->getMessage();
	
	std::string helpMessage;
	if (sender == "Controller")
	{
	    if (message == "Forward")
	    {
		helpMessage = core->getGame()->stepForward();
	    } else if (message == "Backward") {
		helpMessage = core->getGame()->stepBackward();
	    }
	}
	core->getRenderer()->setMessage(helpMessage.empty() ? helpText : helpMessage);
    }
}


}