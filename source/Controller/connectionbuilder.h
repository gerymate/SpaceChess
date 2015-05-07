#ifndef CONNECTIONBUILDER_H
#define CONNECTIONBUILDER_H

#include <SFML/Network.hpp>
#include <string>

namespace Controller
{

class ConnectionBuilder
{
    sf::TcpSocket* client;
    bool thisIsAServer;
    std::string remoteAddress;

    unsigned short portNumber {54321};
    sf::TcpListener listener;
    std::string helperMessage {""};
    bool connected {false};
    
    void setInitialConnectionMessage();
    void setPortNumber();
    void acceptConnection();
    void connectToServer();

public:
    ConnectionBuilder(sf::TcpSocket* theClient, bool isServer = true, 
		      const std::string& theRemoteAddress = "localhost");
    void startListening();
    void establishConnection();
    bool success();
    std::string getInfoMessage() const;
};

}

#endif // CONNECTIONBUILDER_H
