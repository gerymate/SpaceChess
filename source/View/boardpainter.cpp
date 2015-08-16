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
    targetZoomLevel += 0.25f ;
    if (targetZoomLevel > MAXZOOMLEVEL)
    {
	targetZoomLevel = MAXZOOMLEVEL;
    }
}

void BoardPainter::zoomOut()
{
    targetZoomLevel -= 0.25f;
    if (targetZoomLevel < MINZOOMLEVEL)
    {
	targetZoomLevel = MINZOOMLEVEL;
    }
}

void BoardPainter::update()
{    
    for (auto& rank : drawableRanks)
    {
	rank.setZoomLevel(targetZoomLevel);
	rank.update();
    }
}

void BoardPainter::draw()
{            
    //drawBoardDecorations();
    
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
	if (rank.isClosestToViewer() && rank.getRect().contains(screenPosition))
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

void BoardPainter::drawBoardDecorations()
{
    // draw notation to the upper left corner
    sf::Text notation("", style->fontManager->font, style->getFontSize());
    sf::Color numberColor { sf::Color::Yellow };
    notation.setColor(numberColor);
    notation.setStyle(sf::Text::Bold);

    for (int j = 0; j != 5; ++j)
    {
	sf::Vector2f position(style->getBoardTopLeft() + sf::Vector2f(0.f, j * style->getFieldSize()));
	drawRowDecoration(position, j);
    }

    // draw notation under the plane
    sf::Color letterColor { sf::Color::Red };
    notation.setColor(letterColor);
    notation.setStyle(sf::Text::Regular);
    for (int i = 0; i != 5; ++i)
    {
	notation.setString(style->XNotation[i]);
	sf::Vector2f offset { style->getBoardTopLeft().x + i * style->getFieldSize(), style->getBoardTopLeft().y };
	sf::Vector2f topLeft { offset + style->getBottomNotationPosition() };
	notation.setPosition(topLeft);
	canvas->draw(notation);
    }    
}

void BoardPainter::drawRowDecoration(sf::Vector2f thePosition, int row)
{
    // draw notation beside the plane
    sf::Text notation(style->YNotation[4 - row], style->fontManager->font, style->getFontSize());
    sf::Color letterColor { sf::Color::Red };
    notation.setColor(letterColor);
    notation.setPosition(thePosition + style->getLeftNotationPosition());
    canvas->draw(notation);
}


}