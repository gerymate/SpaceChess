#include "figure.h"
#include <iostream>

namespace Model 
{

std::ostream& operator<<(std::ostream& outputStream, const Model::Figure figure)
{
    switch(figure)
    {
	case Figure::None: outputStream << "X"; break;
	case Figure::King: outputStream << "K"; break;
	case Figure::Queen: outputStream << "Q"; break;
	case Figure::Rook: outputStream << "R"; break;
	case Figure::Bishop: outputStream << "B"; break;
	case Figure::Knight: outputStream << "N"; break;
	case Figure::Unicorn: outputStream << "U"; break;
	case Figure::Pawn: outputStream << "P"; break;
    }
    return outputStream;
}

}