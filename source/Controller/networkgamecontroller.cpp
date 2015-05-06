#include "networkgamecontroller.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace Controller
{

NetworkGameController::NetworkGameController(sf::RenderWindow* theWindow, 
					     bool isServer, 
					     const string& theParams)
    : LocalGameController{theWindow}, thisIsAServer{isServer}, remoteAddress{theParams}
{
    client.setBlocking(false);
}

void NetworkGameController::handleConnections()
{
    switch (connectionStatus)
    {
	case Phase::Init:
	    showConnectionMessage();
	    if (thisIsAServer) startListening();
	    connectionStatus = Phase::Connecting;
	case Phase::Connecting:
	    establishConnection();
	    break;
	case Phase::Established:
	    renderer.setMessage("Connection established.");
	    connectionStatus = Phase::Connected;
	case Phase::Connected:
	    // handle networking here..
	    break;
	case Phase::Disconnected:
	    renderer.setMessage("Connection ended.");
	default:
	    break;
    }
}

void NetworkGameController::showConnectionMessage()
{
    std::string helperMessage {""};
    if (thisIsAServer)
    {
	helperMessage = "Waiting for an incoming connection request...";
	renderer.setMessage(helperMessage);
    } else {
	helperMessage.append("Trying to connect to ").append(remoteAddress);
	renderer.setMessage(helperMessage);
    }
}

void NetworkGameController::establishConnection()
{
    if (thisIsAServer)
    {
	acceptConnection();
    } else {
	connectToServer();
    }
}

void NetworkGameController::startListening()
{
    sf::Socket::Status status;
    status = listener.listen(portNumber);
    
    if (status != sf::Socket::Done)
    {
	std::cerr 	<< "Network error: cannot listen on port " 
			<< portNumber 
			<< ".\nCheck firewall...\n";
	exit(1);
    }
    listener.setBlocking(false);
}

void NetworkGameController::acceptConnection()
{
    sf::Socket::Status status;
    status = listener.accept(client);
    if (status == sf::Socket::Error)
    {
	std::cerr << "Network error: connection failed.\n";
	exit(1);	
    } else if (status == sf::Socket::Done) {
	connectionStatus = Phase::Established;
    }
}

void NetworkGameController::connectToServer()
{
    sf::Socket::Status status = client.connect(remoteAddress, portNumber);
    if (status == sf::Socket::Done) 
    {
	connectionStatus = Phase::Established;
    } else if (status == sf::Socket::Error) {   
 	std::cerr << "Connection to server " << remoteAddress << " failed. Sorry.\n";
	exit(1);
    }
}

NetworkGameController::~NetworkGameController()
{
    client.disconnect();
}

void NetworkGameController::mainLoop()
{
    while (window->isOpen())
    {    
	handleSystemEvents();
	handleConnections();
	if (connectionStatus == Phase::Connected)
	{
	    handleGameEvents();
	}
	renderer.update();
    }
    saveGame();
}

void NetworkGameController::handleGameEvents()
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

void NetworkGameController::handleSystemEvents()
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

}