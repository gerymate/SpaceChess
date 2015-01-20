#include <iostream>
#include <fstream>
#include "game.h"
#include "gamestate.h"
#include "boardpainter2d.h"
#include <SFML/Graphics.hpp>

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
  
    // init the model
    GameState initialBoard { loadBoard() };
    Game model { initialBoard };
    
    // init the 2D View
    sf::RenderWindow window;
    window.create( sf::VideoMode {1200, 600}, "SpaceChess" );
    BoardPainter2D scene {&window};
        
    GameState state = model.getGameState();
    scene.init();

    cout << state;
    scene.update(state);

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
        scene.update(state);

        char temp[100];
        cin.getline(temp, 100);
    }
        
    //cout << endl;
    
    moveFile.close();
    scene.shutdown();
    window.close();        

    return 0;
}
