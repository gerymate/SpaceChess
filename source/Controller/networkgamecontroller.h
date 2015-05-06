#ifndef NETWORKGAMECONTROLLER_H
#define NETWORKGAMECONTROLLER_H

#include "common.h"
#include "localgamecontroller.h"
#include <SFML/Network.hpp>

namespace Controller
{
    
class NetworkGameController : public LocalGameController
{
    bool thisIsAServer {true};
    sf::TcpSocket client;
    sf::TcpListener listener;
    const unsigned short portNumber {54321};
    std::string remoteAddress{""};
    enum class Phase
    {
	Init, Connecting, Established, Connected, Disconnected
    } connectionStatus { Phase::Init };

    void handleSystemEvents() override;
    void handleGameEvents() override;
    void handleConnections();
    void establishConnection();
    void startListening();
    void acceptConnection();
    void connectToServer();
    void showConnectionMessage();
    
public:
    NetworkGameController(sf::RenderWindow* theWindow, bool isServer = true, const std::string& theParams = "");
    virtual ~NetworkGameController();
    virtual void mainLoop();
};

}
#endif // NETWORKGAMECONTROLLER_H
