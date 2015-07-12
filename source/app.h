// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#ifndef APP_H
#define APP_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Controller/gamecontroller.h"
#include <memory>

class App
{
    std::string mode, params;
    std::unique_ptr<Controller::GameController> gameController;
    sf::RenderWindow window;
    void setUpWindow();
    void setUpAGameController();
public:
    App(std::string theMode = "", std::string theParams = "");
    int run();
    
    static void showUsage(std::string executable);
};

#endif // APP_H
