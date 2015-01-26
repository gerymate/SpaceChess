#ifndef APP_H
#define APP_H

#include <SFML/Graphics.hpp>
#include "Controller/gamecontroller.h"
#include <memory>

class App
{
    std::unique_ptr<GameController> gameController;
    sf::RenderWindow window;
    void setUpWindow();
    void setUpAGameController();
    void dispatchEventLoop();
public:
    App();
    int run();
};

#endif // APP_H
