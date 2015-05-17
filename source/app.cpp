#include "app.h"
#include <iostream>
#include <fstream>
#include "Controller/localgamecontroller.h"
#include "Controller/networkgamecontroller.h"
#include "Controller/playbackcontroller.h"
using namespace std;
using namespace Controller;

App::App(string theMode, string theParams) : mode(theMode), params(theParams)
{
}

int App::run()
{    
    try {
	setUpWindow();
	setUpAGameController();
	gameController->mainLoop();
    } catch (std::exception& e) {
	std::cerr << "Problem:\n" << e.what() << "\n";
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
    } else if (mode == "-s") {
	gameController.reset(new NetworkGameController(&window, true, params));
    } else if (mode == "-c") {
	gameController.reset(new NetworkGameController(&window, false, params));	
    } else if (mode.empty()) {
	gameController.reset(new LocalGameController(&window));
    } else {
	showUsage("SpaceChess");
	exit(0);
    }
}

void App::showUsage(std::string executable)
{
	std::cout << "\nUsage:\n\n SpaceChess [mode] [argument]\n\n";
	std::cout << "Run without any arguments for a local game.\n";
	std::cout << "Run with '-r [FILENAME]' to watch a previously saved game.\n";
	std::cout << "Run with '-s [PORTNUMBER]' for a networked game accepting a remote connection.\n";
	std::cout << "Run with '-c IP_ADDRESS[:PORTNUMBER]' to connect to a remote game.\n\n";
}