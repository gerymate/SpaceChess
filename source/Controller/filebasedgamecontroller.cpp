#include "Controller/filebasedgamecontroller.h"

using namespace std;

FileBasedGameController::FileBasedGameController(sf::RenderWindow* theWindow) : window{theWindow}, boardPainter{theWindow}
{
    // init the model
    game.setGameState(loadBoardFromFile());
    initFileBasedGame();
}

void FileBasedGameController::initFileBasedGame()
{
    string fileNameOfFileOfMoves("move.list");
    fileOfMoves.open(fileNameOfFileOfMoves);
    if (!fileOfMoves.is_open()) {
        cerr << "Error, file not fould: " << fileNameOfFileOfMoves << endl;
	throw new std::exception;
    }

    Model::GameState currentState = game.getGameState();
    cout << currentState;
    boardPainter.update(currentState);
}

bool FileBasedGameController::update(sf::Event event)
{
    Model::GameState state;
    Model::Coord nextMove;
    if (! (fileOfMoves >> nextMove)) return false;
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
}

FileBasedGameController::~FileBasedGameController()
{
    fileOfMoves.close();
}

void FileBasedGameController::dispatchEvents()
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
		default:
		    break;
	    }
	}
    }    

}


