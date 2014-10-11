#include <iostream>
#include <fstream>
#include "game.h"
#include "gamestate.h"
#include "view.h"

int main(int argc, char** argv)
{
    // load file "initial.board"
    std::string boardFileName("initial.board");
    std::ifstream boardFile(boardFileName);
    if (!boardFile.is_open()) {
        std::cerr << "Error, file not fould: " << boardFileName << std::endl;
        return 1;
    }
    
    GameState initialBoard;
    boardFile >> initialBoard;
    boardFile.close();

    Game model(initialBoard);
    
    // init 2D View
    View scene;
    scene.init();
        
    GameState state = model.getGameState();
    std::cout << state;
    scene.update();

    // load file "move.list" and play
    std::string moveFileName("move.list");
    std::ifstream moveFile(moveFileName);
    if (!moveFile.is_open()) {
        std::cerr << "Error, file not fould: " << moveFileName << std::endl;
        return 1;
    }

    Coord place;
    bool isLegalMove = true;
    while(isLegalMove && moveFile >> place) {
        isLegalMove = model.touch(place);
        std::cout << place << " (" << state.board.at(place) << ") ";
        if (isLegalMove) {
            std::cout << "OK\t";
            state = model.getGameState();
            if (state.phase == 0) {
                std::cout << std::endl << state;
            }
        } else {
            std::cout << "Illegal move." << std::endl;
        }
        scene.update();
    }
    
    char temp[100];
    std::cin.getline(temp, 100);
    
    //std::cout << std::endl;
    
    moveFile.close();
    scene.shutdown();
    return 0;
}
