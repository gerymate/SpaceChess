// (C) Máté Gergely - gerymate@gmail.com
#include "networkgamecontroller.h"
#include <iostream>
#include <fstream>
#include "irenderer.h"

using namespace std;

namespace Controller
{

NetworkGameController::NetworkGameController(std::shared_ptr<Core> theCore, 
					     bool isServer, 
					     const string& theParams)
    : LocalGameController{theCore}
    , connectionBuilder{&client, isServer, theParams}
{
    client.setBlocking(false);
    localPlayer = isServer ? Model::Player::White : Model::Player::Black;
    core->getRenderer()->setLocalPlayers(localPlayer);
}

void NetworkGameController::mainLoop()
{
    while (core->getRenderer()->getWindow()->isOpen())
    {    
	handleSystemEvents();
	handleConnections();
	handleGameEvents();
	core->getRenderer()->update();
    }
    saveGame();
}

void NetworkGameController::handleSystemEvents()
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
		    if (localPlayerIsNextPlayer() && connected)
		    {
			sf::Vector2f mousePosition { sf::Mouse::getPosition(*window) };
			core->getRenderer()->handleClick(mousePosition);
		    }
		}
		break;
	    default:
		break;
	}
    }
}

bool NetworkGameController::localPlayerIsNextPlayer()
{
    return localPlayer == core->getGame()->getNextPlayer();
}

void NetworkGameController::handleConnections()
{
    View::IRenderer* renderer { core->getRenderer() };
    switch (connectionStatus)
    {
	case NetworkPhase::Init:
	    renderer->setMessage(connectionBuilder.getInfoMessage());
	    connectionBuilder.startListening();
	    connectionStatus = NetworkPhase::Connecting;
	case NetworkPhase::Connecting:
	    connectionBuilder.establishConnection();
	    if (connectionBuilder.success()) connectionStatus = NetworkPhase::Established;
	    break;
	case NetworkPhase::Established:
	    connected = true;
	    renderer->setMessage("Connection established.");
	    connectionStatus = NetworkPhase::Connected;
	case NetworkPhase::Connected:
	    handleCommunication();
	    break;
	case NetworkPhase::Disconnected:
	    connected = false;
	    renderer->setMessage("Connection ended.");
	default:
	    break;
    }
}

void NetworkGameController::handleCommunication()
{
    try {
	if (localPlayer != core->getGame()->getHistory()->getNextPlayer())
	{
	    sf::Packet packet;
	    sf::Socket::Status status = client.receive(packet);

	    if (status == sf::Socket::Error) 
	    {
		throw std::runtime_error("Error receiving data over the network.");
	    } else if (status == sf::Socket::Disconnected) {
		connectionStatus = NetworkPhase::Disconnected;
	    } else if (status == sf::Socket::Done) {
		// unpack move
		std::string moveDesc;
		packet >> moveDesc;
		// make move
		Model::Position from {moveDesc.substr(0,3)};
		Model::Position to {moveDesc.substr(4, 3)};
		std::string message = core->getGame()->move(from, to);
		core->getRenderer()->setMessage(message);
	    }
	}
    } catch (std::exception& e) {
	core->getRenderer()->setMessage("Network error. Sorry. Game will be saved on exit.");
	std::cerr << e.what();
    }
}

void NetworkGameController::handleGameEvents()
{    
    while (!core->getEventQueue()->empty())
    {
	PointerToEvent event = core->getEventQueue()->front();
	core->getEventQueue()->pop();
	std::string sender = event->getSender();
	
	if (sender == "Board")
	{
	    playerController.handleSelection(event);
	} else if (sender == "PlayerController") {
	    sendMove(event->getParameters());
	}
    }
}

void NetworkGameController::sendMove(const string& moveDesc)
{
    // make packet
    sf::Packet packet;
    packet << moveDesc;
    
    // send move
    sf::Socket::Status status;
    status = client.send(packet);
    
    // check for errors
    if (status == sf::Socket::Disconnected)
    {
	connectionStatus = NetworkPhase::Disconnected;
    } else if (status == sf::Socket::Error) {
	connectionStatus = NetworkPhase::Disconnected;
	core->getRenderer()->setMessage("Network error. Sorry.");
    }
}

NetworkGameController::~NetworkGameController()
{
    client.disconnect();
}


}