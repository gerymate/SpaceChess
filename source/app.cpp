#include "app.h"
#include <iostream>
#include <fstream>
#include "Controller/localgamecontroller.h"
#include "Controller/playbackcontroller.h"
using namespace std;
using namespace Controller;

App::App(string theMode, string theParams) : mode{theMode}, params{theParams}
{
}

int App::run()
{    
    try {
    // init the 2D View
    setUpWindow();
    setUpAGameController();
    gameController->mainLoop();
    } catch (std::exception& e) {
	std::cerr << e.what() << "\n";
	return -1;
    }
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
    if (mode == "-r")
    {
	if (params.empty()) params = "lastspacechessgame.txt";
	gameController.reset(new PlaybackController(&window, params));
    } else {
	gameController.reset(new LocalGameController(&window));
    }
}

void App::showUsage(std::string executable)
{
	std::cout << "Usage:\n\n SpaceChess [mode] [argument]\n\n";
	std::cout << "Run without parameters for a local game.\n\n";
	std::cout << "Run with '-r FILENAME' to watch a previously saved game.\n\n";
	std::cout << "Run with '-s' to play a networked game accepting a remote connection\n\n";
	std::cout << "Run with '-c IP_ADDRESS' to connect to a remote game.\n\n";
}