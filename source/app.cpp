#include "app.h"
#include <iostream>
#include <fstream>

using namespace std;

App::App()
{    
}

int App::run()
{    
    // init the 2D View
    setUpWindow();
    setUpAGameController(); //what kind of?
        
    sf::Event event;
    while (window.isOpen())
    {
	while (window.pollEvent(event))
	{
	    switch (event.type)
	    {
		case sf::Event::Closed:
		    window.close();
		    break;
		case sf::Event::MouseButtonPressed:
		    if ( ! gameController->update(event) ) window.close();
		    break;
		default:
		    break;
	    }
	}
    }    
    return 0;
}

void App::setUpWindow()
{
    window.create( sf::VideoMode {1200, 600}, "SpaceChess" );
}

void App::setUpAGameController()
{
    gameController.reset(new GameController(&window));
}