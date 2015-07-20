// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "boardpainter.h"

#include <iostream>

namespace View {

const int BoardPainter::numberOfRanks {5};
    
BoardPainter::BoardPainter(sf::RenderTarget* theCanvas, StyleSheet* theStyleSheet, 
			   Model::IGameInfo* theGame, EventQueue* theEventQueue)
    : canvas{theCanvas}, style{theStyleSheet}, game{theGame}
    , eventQueue{theEventQueue}
{
    highlightedFields = nullptr;
    buildRanks();   
}

void BoardPainter::buildRanks()
{
    drawableRanks.clear();
    for (int rank = 0; rank != numberOfRanks; ++rank)
    {
	drawableRanks.emplace_back(topLeft, style, rank, game->getBoardInfo());
    }
}

void BoardPainter::setGameState(const Model::GameState* theGameState)
{
    gameState = theGameState;
    board = &(gameState->board);
}

void BoardPainter::setLocalPlayers(Model::Player theLocalPlayers)
{
    localPlayers = theLocalPlayers;
}

void BoardPainter::handleClick(sf::Vector2f& mousePosition)
{
    setAndGetBoardCursorFromScreenPosition(mousePosition);
    if (cursor != Model::Position::Invalid)
    {
	std::string sender { "Board" };
	std::string message { "Selection" };
	std::string params { cursor.getNotation() };
	PointerToEvent event {new Event {sender, message, params} };
	eventQueue->push(event);
    }
}


void BoardPainter::update()
{
}

void BoardPainter::draw()
{        
    for (int i = 0; i != numberOfRanks; ++i)
    {
	drawableRanks.at(i).update(topLeft);
    }
    
    if (localPlayers == Model::Player::Both || localPlayers == gameState->nextPlayer)
    {
	highlightFieldUnderCursor();
	highlightTouchedField();
	highlightPossibleMoves();
    }
    
    for (auto& rank : drawableRanks)
    {
	canvas->draw(rank);
    }
}

void BoardPainter::highlightFieldUnderCursor()
{
    if (cursor != Model::Position::Invalid)
    {
	drawableRanks.at(cursor.getRank()).highlight(cursor, Highlight::Cursor);
    }    
}

void BoardPainter::highlightTouchedField()
{
    if (selectedField != Model::Position::Invalid)
    {
	drawableRanks.at(selectedField.getRank()).highlight(selectedField, Highlight::Touched);
    }
}

void BoardPainter::highlightPossibleMoves()
{
    if (highlightedFields != nullptr)
    {
	for (Model::Position& pos : *highlightedFields)
	{
	    drawableRanks.at(pos.getRank()).highlight(pos, Highlight::PossibleMove);
	}
    }
}


Model::Position BoardPainter::getFieldPositionFromScreenPosition(sf::Vector2f screenPosition)
{
    Model::Position cursor {Model::Position::Invalid};

    for (auto& rank : drawableRanks)
    {
	if (rank.getBoundaries().contains(screenPosition))
	{
	    cursor = rank.getFieldPositionFromScreenPosition(screenPosition);
	    break;
	}
    }
    return cursor;
}

Model::Position BoardPainter::setAndGetBoardCursorFromScreenPosition(sf::Vector2f screenPosition)
{
    return cursor = getFieldPositionFromScreenPosition(screenPosition);
}

sf::FloatRect BoardPainter::getRect() const
{
    sf::Vector2f size { (float)canvas->getSize().x, (float)style->BOARDHEIGHT };
    return sf::FloatRect{ topLeft, size };
}


}