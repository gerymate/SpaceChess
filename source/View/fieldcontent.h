// (C) Máté Gergely - gerymate@gmail.com
#ifndef FIELDCONTENT_H
#define FIELDCONTENT_H

#include "common.h"
#include "Model/position.h"
#include "player.h"
#include "Model/figure.h"

namespace View {

struct FieldContent
{
	Model::Player owner;
	Model::Figure figure;
	Model::Position position;
	FieldContent(Model::PointerToPiece thePiece, Model::Position thePosition = Model::Position());	
};

}
#endif
