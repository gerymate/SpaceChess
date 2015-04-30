#include "boardpainter.h"

#include <iostream>

namespace View {

BoardPainter::BoardPainter(sf::RenderTarget* theCanvas, StyleSheet* theStyleSheet, Model::Game* theGame, Controller::EventQueue* theEventQueue)
    : canvas(theCanvas), style(theStyleSheet), game(theGame), eventQueue(theEventQueue)
{

}

void BoardPainter::setGameState(const Model::GameState* theGameState)
{
    gameState = theGameState;
    board = &(gameState->board);
}

void BoardPainter::handleClick(sf::Vector2f& mousePosition)
{
    // generate event for controller

}


void BoardPainter::draw()
{
    drawableFields.clear();
    
    const int numberOfPlanes = 5;
    for (int i = 0; i != numberOfPlanes; ++i)
    {
	currentPlane = i;
	float xOffset = style->MARGINSIZE + i * (style->MARGINSIZE + style->PLANESIZE);
	sf::Vector2f position {topLeft};
	position += sf::Vector2f(xOffset, style->MARGINSIZE);
	buildPlane(position);
	drawPlaneDecoration(position);
    }
    
    highlightFieldUnderCursor();
    highlightTouchedField();
    
    for (auto& field : drawableFields)
    {
	canvas->draw(field);
    }
    
}

void BoardPainter::highlightFieldUnderCursor()
{
    for (Field& field : drawableFields)
    {
	if (field.getCoord() == cursor)
	{
	    field.setUnderCursor();
	} else {
	    field.notUnderCursor();
	}
    }
}

void BoardPainter::highlightTouchedField()
{
    if (gameState->phase == 1)
    {
	for (Field& field : drawableFields)
	{
	    if (field.getCoord() == gameState->touched)
	    {
		field.setTouched();
	    } else {
		field.notTouched();
	    }
	}	
    }
}

void BoardPainter::drawPlaneDecoration(sf::Vector2f thePosition)
{
    // draw notation to the upper left corner
    sf::Text notation(style->YNotation[currentPlane], style->font, 0.5f * style->MARGINSIZE);
    notation.setColor(sf::Color::Yellow);
    notation.setStyle(sf::Text::Bold);
    notation.setPosition(thePosition + sf::Vector2f(-0.4f * style->MARGINSIZE, -0.6f * style->MARGINSIZE));
    canvas->draw(notation);

    for (int j = 0; j != 5; ++j)
    {
	sf::Vector2f position(thePosition + sf::Vector2f(0.f, j * style->FIELDSIZE));
	currentRow = j;
	drawRowDecoration(position);
    }

    // draw notation under the plane
    notation.setColor(sf::Color::Red);
    notation.setStyle(sf::Text::Regular);
    for (int i = 0; i != 5; ++i)
    {
	notation.setString(style->XNotation[i]);
	sf::Vector2f offset(thePosition.x + i * style->FIELDSIZE, thePosition.y);
	notation.setPosition(offset + sf::Vector2f(0.4f * style->FIELDSIZE, 5.f * style->FIELDSIZE));
	canvas->draw(notation);
    }    
}

void BoardPainter::drawRowDecoration(sf::Vector2f thePosition)
{
    // draw notation beside the plane
    sf::Text notation(style->ZNotation[4 - currentRow], style->font, 0.5f * style->MARGINSIZE);
    notation.setColor(sf::Color::Red);
    notation.setPosition(thePosition + sf::Vector2f(-0.5f * style->MARGINSIZE, 1.f * (style->FIELDSIZE - style->MARGINSIZE)));
    canvas->draw(notation);
}

void BoardPainter::buildPlane(sf::Vector2f thePosition)
{    
    for (int j = 0; j != 5; ++j)
    {
	currentRow = j;
	sf::Vector2f position(thePosition + sf::Vector2f(0.f, j * style->FIELDSIZE));
	buildRow(position);
    }
}

void BoardPainter::buildRow(sf::Vector2f thePosition)
{    
    for (int k = 0; k != 5; ++k)
    {
	currentColumn = k;
	sf::Vector2f position(thePosition + sf::Vector2f(k * style->FIELDSIZE, 0.f));
	const Model::Field content {board->space[currentPlane][currentColumn][4 - currentRow]};
	drawableFields.emplace_back(position, style, board->space[currentPlane][currentColumn][4 - currentRow]);
    }
}

Model::Coord BoardPainter::getFieldCoordByPosition(sf::Vector2f position)
{
    Model::Coord cursor {-1, -1, -1};
    for (auto field : drawableFields)
    {
	if (field.getBoundaries().contains(position))
	{
	    cursor = field.getCoord();
	    break;
	}
    }
    return cursor;
}

Model::Coord BoardPainter::setAndGetCursorByPosition(sf::Vector2f position)
{
    return cursor = getFieldCoordByPosition(position);
}

sf::FloatRect BoardPainter::getRect() const
{
    sf::Vector2f size { (float)canvas->getSize().x, (float)style->BOARDHEIGHT };
    return sf::FloatRect{ topLeft, size };
}


}