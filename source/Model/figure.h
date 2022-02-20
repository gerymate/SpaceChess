// (C) Máté Gergely - gerymate@gmail.com
#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

namespace Model {

enum class Figure 
{
    None = 0, King = 1, Queen = 2, Rook = 3, Bishop = 4, Knight = 5, Unicorn = 6, Pawn = 7
};

std::ostream& operator<<(std::ostream& outputStream, const Model::Figure figure);


}

#endif