// (C) Máté Gergely - gerymate@gmail.com
#include "fieldcontent.h"
#include "Model/piece.h"

namespace View {

FieldContent::FieldContent(Model::PointerToPiece thePiece, Model::Position thePosition) 
{
    if (thePiece != nullptr) {
	owner = thePiece->getPlayer();
	figure = thePiece->getFigure();
	position = thePiece->getPosition();
    } else {
	owner = Model::Player::Nobody;
	figure = Model::Figure::None;
	position = thePosition;
    }
}

}