#include "playbackcontroller.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace Controller
{

PlaybackController::PlaybackController(sf::RenderWindow* theWindow, const std::string& fileName)
    : GameController(theWindow)
{
    renderer.setLocalPlayers(Model::Player::Nobody);
    std::string textToDisplay {"Playback mode: left click for previous move, right click for next."};
    renderer.setMessage(textToDisplay);
    loadGame(fileName);
}

PlaybackController::~PlaybackController()
{
}

void PlaybackController::mainLoop()
{
    while (window->isOpen())
    {    
	handleSystemEvents();
	handleGameEvents();
	renderer.update();
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
	inputFile >> game;
	inputFile.close();
    } catch (std::exception& e) {
	std::cerr << e.what() << "\n";
	exit(1);
    }
}

void PlaybackController::handleSystemEvents()
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
    eventQueue.push(event);
}

void PlaybackController::emitStepBackwardEvent()
{
    std::string sender { "Controller" };
    std::string message { "Backward" };
    std::string params { "" };
    PointerToEvent event {new Event {sender, message, params} };
    eventQueue.push(event);
}

void PlaybackController::handleGameEvents()
{
    while (!eventQueue.empty())
    {
	PointerToEvent event = eventQueue.front();
	eventQueue.pop();
	std::string sender = event->getSender();
	std::string message = event->getMessage();
		
	if (sender == "Controller")
	{
	    if (message == "Forward")
	    {
		game.stepForward();
	    } else if (message == "Backward") {
		game.stepBackward();
	    }
	}
    }
}


}