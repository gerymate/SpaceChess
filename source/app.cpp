#include "app.h"
#include <iostream>
#include <fstream>
#include "Controller/filebasedgamecontroller.h"
#include "Controller/localgamecontroller.h"
using namespace std;

App::App()
{    
}

int App::run()
{    
    // init the 2D View
    setUpWindow();
    setUpAGameController(); //what kind of?
    gameController->dispatchEvents();
    return 0;
}

void App::setUpWindow()
{
    window.create( sf::VideoMode {1200, 400}, "SpaceChess" );
}

void App::setUpAGameController()
{
    gameController.reset(new LocalGameController(&window));
}