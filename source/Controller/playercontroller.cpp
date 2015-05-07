#include "playercontroller.h"

namespace Controller 
{

PlayerController::PlayerController(Model::Game* theGame, 
				   View::Render2D* theRenderer, EventQueue* theEventQueue)
    : game {theGame}, renderer {theRenderer}, eventQueue{theEventQueue}
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
    auto possibleMoves = game->getCurrentlyPossibleMovesFrom(theClickPosition);
    
    if ( possibleMoves != nullptr ) // if there is a figure on that field
    {
	firstSelection = theClickPosition;	
	renderer->setSelectedField(firstSelection);
	renderer->setHighlightedFields(possibleMoves);
    }
}

void PlayerController::handleSecondSelection(Model::Position theClickPosition)
{
    if ( firstSelection == theClickPosition )
    {
	firstSelection = Model::Position::Invalid;
	renderer->clearSelectedField();
	renderer->clearHighlightedFields();
	return;
    }
    
    std::string moveResult = game->move(firstSelection, theClickPosition);
    renderer->setMessage(moveResult);
    
    if (moveResult != "Invalid move")
    {
	std::string sender { "PlayerController" };
	std::string message { "Move" };
	std::string params { moveResult };
	PointerToEvent event {new Event {sender, message, params} };
	eventQueue->push(event);

	firstSelection = Model::Position::Invalid;
	renderer->clearSelectedField();
	renderer->clearHighlightedFields();
    }
}


}