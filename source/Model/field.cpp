#include "field.h"

namespace Model {

Field::Field(Player _owner, Figure _figure, Coord _place) 
	: owner(_owner), figure(_figure), place(_place) 
{
}


std::ostream& operator<<(std::ostream& os, const Field& field)
{
	char owner, figure;
	switch (field.owner) {
		case 1 : owner = 'w'; break;
		case 2 : owner = 'b'; break;
		default : owner = '.'; break;
	}
	switch(field.figure) {
	    case Figure::King : figure = 'K'; break;
	    case Figure::Queen : figure = 'Q'; break;
	    case Figure::Rook : figure = 'R'; break;
	    case Figure::Bishop : figure = 'B'; break;
	    case Figure::Knight : figure = 'N'; break;
	    case Figure::Unicorn : figure = 'U'; break;
	    case Figure::Pawn : figure = 'P'; break;
	    default: figure = (field.place.getColour() == Coord::WHITE) ? 'O' : '0';
	}
	os << owner << figure;
    return os;
}

std::istream& operator>>(std::istream& is, Field& field)
{
	char owner, figure;
	is >> owner >> figure;
	switch (owner) {
	    case 'w' : field.owner = Player::White; break;
	    case 'b' : field.owner = Player::Black; break;
	    default : field.owner = Player::Nobody; break;
	}
	switch(figure) {
	    case 'K' : field.figure = Figure::King; break;
	    case 'Q' : field.figure = Figure::Queen; break;
	    case 'R' : field.figure = Figure::Rook; break;
	    case 'B' : field.figure = Figure::Bishop; break;
	    case 'N' : field.figure = Figure::Knight; break;
	    case 'U' : field.figure = Figure::Unicorn; break;
	    case 'P' : field.figure = Figure::Pawn; break;
	    default: field.figure = Figure::None;
	}
	return is;
}

}