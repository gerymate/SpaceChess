#include "playercontroller.h"

namespace Controller 
{

PlayerController::PlayerController(Model::Game* theGame, View::Render2D* theRenderer)
    : game {theGame}, renderer {theRenderer}
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
    
    std::string message = game->move(firstSelection, theClickPosition);
    if (message == "Invalid move")
    {
	// tell the view the message...
    }
    else
    {
	firstSelection = Model::Position::Invalid;
	renderer->clearSelectedField();
	renderer->clearHighlightedFields();
    }
}


}