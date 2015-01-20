#include "field.h"

Field::Field(int _owner, int _figure, Coord _place) 
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
		case 1 : figure = 'K'; break;
		case 2 : figure = 'Q'; break;
		case 3 : figure = 'R'; break;
		case 4 : figure = 'B'; break;
		case 5 : figure = 'N'; break;
		case 6 : figure = 'U'; break;
		case 7 : figure = 'P'; break;
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
		case 'w' : field.owner = 1; break;
		case 'b' : field.owner = 2; break;
		default : field.owner = 0; break;
	}
	switch(figure) {
		case 'K' : field.figure = 1; break;
		case 'Q' : field.figure = 2; break;
		case 'R' : field.figure = 3; break;
		case 'B' : field.figure = 4; break;
		case 'N' : field.figure = 5; break;
		case 'U' : field.figure = 6; break;
		case 'P' : field.figure = 7; break;
		default: field.figure = 0;
	}
	return is;
}
