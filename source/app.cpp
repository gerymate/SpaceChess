// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "app.h"
#include <iostream>
#include <fstream>
#include "Controller/localgamecontroller.h"
#include "Controller/networkgamecontroller.h"
#include "Controller/playbackcontroller.h"
#include "View/render25d.h"
using namespace std;
using namespace Controller;

App::App(string theMode, string theParams) : mode(theMode), params(theParams)
{
}

int App::run()
{    
    try {
	setUpWindow();
	setUpRenderer();
	setUpCore();
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
    settings.antialiasingLevel = 4;
    window.create( sf::VideoMode {600, 700}, "SpaceChess", sf::Style::Default, settings );
}

void App::setUpRenderer()
{
    renderer.reset(new View::Render25D(&window, &game, &eventQueue));
}

void App::setUpCore()
{
    core.reset(new Core(&game, &eventQueue, renderer.get() ));
}

void App::setUpAGameController()
{
    if (mode == "-r")
    {
	if (params.empty()) params = "lastspacechessgame.txt";
	gameController.reset(new PlaybackController(core, params));
    } else if (mode == "-s") {
	gameController.reset(new NetworkGameController(core, true, params));
    } else if (mode == "-c") {
	gameController.reset(new NetworkGameController(core, false, params));	
    } else if (mode.empty()) {
	gameController.reset(new LocalGameController(core));
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

void App::log(std::string logItem)
{
    std::cout << logItem << "\n";
}
