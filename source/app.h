#ifndef APP_H
#define APP_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Controller/gamecontroller.h"
#include <memory>

class App
{
    std::string mode;
    std::unique_ptr<Controller::GameController> gameController;
    sf::RenderWindow window;
    void setUpWindow();
    void setUpAGameController();
public:
    App();
    App(std::string theMode, std::string param = "");
    int run();
};

#endif // APP_H
