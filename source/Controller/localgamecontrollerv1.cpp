#include "localgamecontrollerv1.h"
#include <iostream>

using namespace std;

LocalGameControllerV1::LocalGameControllerV1(sf::RenderWindow* theWindow) : window{theWindow}, renderer{theWindow}
{
    // init the model
    game.setGameState(loadBoardFromFile());
    initLocalGame();
}

void LocalGameControllerV1::initLocalGame()
{
    Model::GameState currentState = game.getGameState();
    renderer.update(currentState);
}


LocalGameControllerV1::~LocalGameControllerV1()
{

}

void LocalGameControllerV1::dispatchEvents()
{
    sf::Event event;
    while (window->isOpen())
    {
	while (window->pollEvent(event))
	{
	    switch (event.type)
	    {
		case sf::Event::Closed:
		    window->close();
		    break;
		case sf::Event::MouseButtonPressed:
		    game.touch(cursor);
		    break;
		case sf::Event::MouseMoved:
		    setCursor(event);
		    break;
		default:
		    break;
	    }
	}
	
	renderer.update(game.getGameState());
    }
}

void LocalGameControllerV1::setCursor(sf::Event event)
{
    sf::Vector2f position(event.mouseMove.x, event.mouseMove.y);    
    cursor = renderer.setAndGetCoordByPosition(position);
}


bool LocalGameControllerV1::update(sf::Event event)
{
/*
    Model::GameState state;
    Model::Coord nextMove;
    bool isLegalMove = game.touch(nextMove);
    
    cout << nextMove << " (" << state.board.at(nextMove) << ") ";
    if (isLegalMove) {
	cout << "OK\t";
	state = game.getGameState();
	if (state.phase == 0) {
	    cout << endl << state;
	}
    } else {
	cout << "Illegal move." << endl;
    }
    boardPainter.update(state);
    return isLegalMove;        
  */
return true;
}


