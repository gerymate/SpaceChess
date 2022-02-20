// (C) Máté Gergely - gerymate@gmail.com
#ifndef APP_H
#define APP_H

#include <string>
#include <SFML/Graphics.hpp>
#include "core.h"
#include "Controller/gamecontroller.h"
#include "irenderer.h"
#include <memory>

class App
{
    std::string mode, params;
    
    sf::RenderWindow window;
    Model::Game game;
    EventQueue eventQueue;
    std::shared_ptr<View::IRenderer> renderer;
    std::shared_ptr<Core> core;
    std::unique_ptr<Controller::GameController> gameController;
    void setUpWindow();
    void setUpRenderer();
    void setUpCore();
    void setUpAGameController();
public:
    App(std::string theMode = "", std::string theParams = "");
    int run();
    
    static void showUsage(std::string executable);
    static void log(std::string logItem);
};

#endif // APP_H
