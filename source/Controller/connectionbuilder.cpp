// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "connectionbuilder.h"
#include <iostream>
#include <string>

namespace Controller
{

ConnectionBuilder::ConnectionBuilder(sf::TcpSocket* theClient, bool isServer,
				     const std::string& theRemoteAddress)
    : client{theClient}, thisIsAServer{isServer}, remoteAddress(theRemoteAddress)
{
    helperMessage = "";
    setPortNumber();
    setInitialConnectionMessage();    
}

void ConnectionBuilder::setPortNumber()
{
    std::string port {""};
    if (thisIsAServer)
    {
	port = remoteAddress;
    } else {
	size_t separator = remoteAddress.find(":");
	if (separator != std::string::npos)
	{
	    port = remoteAddress.substr(separator + 1);
	    remoteAddress.erase(separator);
	}	    
    }
    
    if (!port.empty())
    {
	try
	{
	    portNumber = std::stoul(port);
	} catch (std::exception& e) {
	    std::cerr << e.what() << "\nCannot parse address/port number.\n";
	    exit(2);
	}
    }
}

void ConnectionBuilder::setInitialConnectionMessage()
{
    if (thisIsAServer)
    {
	helperMessage = "Waiting for an incoming connection request on port ";
	helperMessage.append(std::to_string(portNumber));
    } else {
	helperMessage = "Trying to connect to ";
	helperMessage.append(remoteAddress).append(" on port ").append(std::to_string(portNumber));
    }
}

void ConnectionBuilder::startListening()
{
    if (thisIsAServer)
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
}

void ConnectionBuilder::establishConnection()
{
    if (thisIsAServer)
    {
	acceptConnection();
    } else {
	connectToServer();
    }
}

void ConnectionBuilder::acceptConnection()
{
    sf::Socket::Status status;
    status = listener.accept(*client);
    if (status == sf::Socket::Error)
    {
	std::cerr << "Network error: connection failed.\n";
	exit(1);	
    } else if (status == sf::Socket::Done) {
	connected = true;
    }
}

void ConnectionBuilder::connectToServer()
{
    sf::Socket::Status status = client->connect(remoteAddress, portNumber);
    if (status == sf::Socket::Done) 
    {
	connected = true;
    } else if (status == sf::Socket::Error) {   
 	std::cerr << "Connection to server " << remoteAddress << " failed. Sorry.\n";
	exit(1);
    }
}

bool ConnectionBuilder::success()
{
    return connected;
}

std::string ConnectionBuilder::getInfoMessage() const
{
    return helperMessage;
}

    
    
}