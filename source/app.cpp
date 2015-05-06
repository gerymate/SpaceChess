#include "app.h"
#include <iostream>
#include <fstream>
#include "Controller/localgamecontroller.h"
#include "Controller/playbackcontroller.h"
using namespace std;
using namespace Controller;

App::App()
{    
}

App::App(string theMode, string theParam) : mode{theMode}
{
}

int App::run()
{    
    // init the 2D View
    setUpWindow();
    setUpAGameController(); //what kind of?
    gameController->mainLoop();
    return 0;
}

void App::setUpWindow()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create( sf::VideoMode {1200, 400}, "SpaceChess", sf::Style::Default, settings );
}

void App::setUpAGameController()
{
    if (mode == "playback")
    {
	gameController.reset(new PlaybackController(&window));
    } else {
	gameController.reset(new LocalGameController(&window));
    }
}