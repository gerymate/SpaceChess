#include "localgamecontroller.h"
#include <iostream>

using namespace std;

LocalGameController::LocalGameController(sf::RenderWindow* theWindow) : window{theWindow}, boardPainter{theWindow}
{
    // init the model
    game.setGameState(loadBoardFromFile());
    initLocalGame();
}

void LocalGameController::initLocalGame()
{
    Model::GameState currentState = game.getGameState();
    boardPainter.update(currentState);
}


LocalGameController::~LocalGameController()
{

}

void LocalGameController::dispatchEvents()
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
		    if ( ! update(event) ) window->close();
		    break;
		case sf::Event::MouseMoved:
		    {
			setCursor(event);
			std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
			std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
			std::cout << "cursor: " << cursor<< std::endl;
			
		    }
		default:
		    break;
	    }
	}
    }
}

void LocalGameController::setCursor(sf::Event event)
{
    sf::Vector2f position(event.mouseMove.x, event.mouseMove.y);
    cursor = boardPainter.getCoordByPosition(position);
}


bool LocalGameController::update(sf::Event event)
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


