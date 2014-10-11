#include <iostream>
#include <fstream>
#include "game.h"
#include "gamestate.h"

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
        
    GameState state = model.getGameState();
    std::cout << state;

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
    }
    
    //std::cout << std::endl;
    moveFile.close();
    return 0;
}
