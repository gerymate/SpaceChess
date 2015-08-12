// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "boardpainter.h"

#include <iostream>
#include <math.h>

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
	drawableRanks.emplace_back(style, rank, game->getBoardInfo());
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

void BoardPainter::zoomIn()
{
    targetZoomLevel++;
    if (targetZoomLevel > MAXZOOMLEVEL)
    {
	targetZoomLevel = MAXZOOMLEVEL;
    }
    Log::that("targetZoomLevel", targetZoomLevel);
}

void BoardPainter::zoomOut()
{
    targetZoomLevel--;
    if (targetZoomLevel < MINZOOMLEVEL)
    {
	targetZoomLevel = MINZOOMLEVEL;
    }
    Log::that("targetZoomLevel", targetZoomLevel);    
}

void BoardPainter::update()
{
}

void BoardPainter::draw()
{        
    for (auto& rank : drawableRanks)
    {
	rank.update();
    }
    
    if (localPlayers == Model::Player::Both || localPlayers == gameState->nextPlayer)
    {
	highlightFieldUnderCursor();
	highlightTouchedField();
	highlightPossibleMoves();
    }

    for (int i = numberOfRanks - 1; i >= 0; --i)
    {
	canvas->draw(drawableRanks.at(i));
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
	if (rank.getRect().contains(screenPosition))
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
    float width { 
	std::max(std::abs(style->getUpperLeftNotationPosition().x), std::abs(style->getLeftNotationPosition().x))
	+ style->getBoardSize()
    };
    float height { 
	std::abs(style->getUpperLeftNotationPosition().y) 
	+ std::abs(style->getBottomNotationPosition().y)
	+ style->getFontSize()
    };
    sf::Vector2f size { width, height };
    return sf::FloatRect{ style->getBoardTopLeft(), size };
}


}