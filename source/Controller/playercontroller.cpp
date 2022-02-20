// (C) Máté Gergely - gerymate@gmail.com
#include "playercontroller.h"

namespace Controller 
{

PlayerController::PlayerController(std::shared_ptr<Core> theCore)
    : core{ theCore }
{
}

void PlayerController::handleSelection(PointerToEvent event)
{
    Model::Position clickPosition {event->getParameters()};
    
    if (!firstSelection.isValid())
    {
	handleFirstSelection(clickPosition);
    }
    else
    {
	handleSecondSelection(clickPosition);
    }    
}

void PlayerController::handleFirstSelection(Model::Position theClickPosition)
{
    auto possibleMoves = core->getGame()->getCurrentlyPossibleMovesFrom(theClickPosition);
    
    if ( possibleMoves != nullptr ) // if there is a figure on that field
    {
	firstSelection = theClickPosition;
	core->getRenderer()->setSelectedField(firstSelection);
	core->getRenderer()->setHighlightedFields(possibleMoves);
    }
}

void PlayerController::handleSecondSelection(Model::Position theClickPosition)
{
    if ( firstSelection == theClickPosition )
    {
	firstSelection = Model::Position::Invalid;
	core->getRenderer()->clearSelectedField();
	core->getRenderer()->clearHighlightedFields();
	return;
    }
    
    std::string moveResult = core->getGame()->move(firstSelection, theClickPosition);
    core->getRenderer()->setMessage(moveResult);
    
    if (moveResult != "Invalid move")
    {
	std::string sender { "PlayerController" };
	std::string message { "Move" };
	std::string params { moveResult };
	PointerToEvent event {new Event {sender, message, params} };
	core->getEventQueue()->push(event);

	firstSelection = Model::Position::Invalid;
	core->getRenderer()->clearSelectedField();
	core->getRenderer()->clearHighlightedFields();
    }
}


}