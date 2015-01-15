#include <iostream>
#include <fstream>
#include "game.h"
#include "gamestate.h"
#include "boardpainter2d.h"

using namespace std;

GameState loadBoard()
{
    // load file "initial.board"
    const string boardFileName("initial.board");
    ifstream boardFile(boardFileName);
    if (!boardFile.is_open()) {
        cerr << "Error, file not fould: " << boardFileName << endl;
        exit(1);
    }

    GameState board;
    boardFile >> board;
    boardFile.close();

    return board;
}

int main(int argc, char** argv)
{
    GameState initialBoard { loadBoard() };

    Game model { initialBoard };
    
    // init 2D View
    BoardPainter2D scene;
    scene.init();
        
    GameState state = model.getGameState();
    cout << state;
    scene.update();

    // load file "move.list" and play
    string moveFileName("move.list");
    ifstream moveFile(moveFileName);
    if (!moveFile.is_open()) {
        cerr << "Error, file not fould: " << moveFileName << endl;
        return 1;
    }

    Coord place;
    bool isLegalMove = true;
    while(isLegalMove && moveFile >> place) {
        isLegalMove = model.touch(place);
        cout << place << " (" << state.board.at(place) << ") ";
        if (isLegalMove) {
            cout << "OK\t";
            state = model.getGameState();
            if (state.phase == 0) {
                cout << endl << state;
            }
        } else {
            cout << "Illegal move." << endl;
        }
        scene.update();

        char temp[100];
        cin.getline(temp, 100);
    }
        
    //cout << endl;
    
    moveFile.close();
    scene.shutdown();
    return 0;
}
