#include "Controller/gamecontroller.h"

#include <iostream>
#include <fstream>

using namespace std;

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