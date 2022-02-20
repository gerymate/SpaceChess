// (C) Máté Gergely - gerymate@gmail.com
#ifndef NETWORKGAMECONTROLLER_H
#define NETWORKGAMECONTROLLER_H

#include "common.h"
#include "localgamecontroller.h"
#include "connectionbuilder.h"
#include <SFML/Network.hpp>

namespace Controller
{
    
class NetworkGameController : public LocalGameController
{
    sf::TcpSocket client;
    ConnectionBuilder connectionBuilder;
    bool connected {false};
    enum class NetworkPhase
    {
	Init, Connecting, Established, Connected, Disconnected
    } connectionStatus { NetworkPhase::Init };
    Model::Player localPlayer;
    
    void handleSystemEvents() override;
    void handleGameEvents() override;
    
    void handleConnections();
    void handleCommunication();
    void sendMove(const std::string& moveDesc);
    bool localPlayerIsNextPlayer();
    
public:
    NetworkGameController(std::shared_ptr<Core> theCore, bool isServer = true, 
			  const std::string& theParams = "");
    virtual ~NetworkGameController();
    virtual void mainLoop();
};

}
#endif // NETWORKGAMECONTROLLER_H
