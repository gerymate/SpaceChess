#include "Controller/gamecontroller.h"

using namespace std;

GameController::GameController(sf::RenderWindow* theWindow) : window{theWindow}, boardPainter{theWindow}
{
    // init the model
    game.setGameState(loadBoardFromFile());
    initFileBasedGame();
}

Model::GameState GameController::loadBoardFromFile()
{
    // load file "initial.board"
    const string fileNameOfBoard("initial.board");
    ifstream boardFile(fileNameOfBoard);
    if (!boardFile.is_open()) {
        cerr << "Error, file not fould: " << fileNameOfBoard << endl;
        exit(1);
    }

    Model::GameState board;
    boardFile >> board;
    boardFile.close();

    return board;
}

void GameController::initFileBasedGame()
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

bool GameController::update(sf::Event event)
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

GameController::~GameController()
{
    fileOfMoves.close();
}

