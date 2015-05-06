#include "boardpainter.h"

#include <iostream>

namespace View {

BoardPainter::BoardPainter(sf::RenderTarget* theCanvas, StyleSheet* theStyleSheet, 
			   Model::Game* theGame, EventQueue* theEventQueue)
    : canvas{theCanvas}, style{theStyleSheet}, game{theGame}
    , eventQueue{theEventQueue}
{
    highlightedFields = nullptr;
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
    
    if (localPlayers == Model::Player::Both || localPlayers == gameState->nextPlayer)
    {
	highlightFieldUnderCursor();
	highlightTouchedField();
	highlightPossibleMoves();
    }
    
    for (auto& field : drawableFields)
    {
	canvas->draw(field);
    }
    
}

void BoardPainter::highlightFieldUnderCursor()
{
    for (Field& field : drawableFields)
    {
	if (field.getPosition() == cursor)
	{
	    field.setUnderCursor();
	    break;
	}
    }
}

void BoardPainter::highlightTouchedField()
{
    if (selectedField != Model::Position::Invalid)
    {
	for (Field& field : drawableFields)
	{
	    if (field.getPosition() == selectedField)
	    {
		field.setTouched();
		break;
	    }
	}	
    }
}

void BoardPainter::highlightPossibleMoves()
{
    if (highlightedFields != nullptr)
    {
	for (Model::Position& pos : *highlightedFields)
	{
	    for (Field& field : drawableFields)
	    {
		if (field.getPosition() == pos)
		{
		    field.setHighlighted();
		    break;
		}
	    }
	}
    }
}

void BoardPainter::drawPlaneDecoration(sf::Vector2f thePosition)
{
    // draw notation to the upper left corner
    sf::Text notation(style->ZNotation[currentPlane], style->font, 0.5f * style->MARGINSIZE);
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
    sf::Text notation(style->YNotation[4 - currentRow], style->font, 0.5f * style->MARGINSIZE);
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
	const Model::Field content {board->space[4 - currentRow][currentColumn][currentPlane]};
	drawableFields.emplace_back(position, style, content);
    }
}

Model::Position BoardPainter::getFieldPositionFromScreenPosition(sf::Vector2f screenPosition)
{
    Model::Position cursor {Model::Position::Invalid};

    for (auto& field : drawableFields)
    {
	if (field.getBoundaries().contains(screenPosition))
	{
	    cursor = field.getPosition();
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