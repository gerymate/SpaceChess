// (C) Máté Gergely - gerymate@gmail.com
#include "rank.h"
#include <cmath>

namespace View {

Rank::Rank(StyleSheet *theStyle, int theRank, Model::IBoardInfo* theBoard) 
    : style{theStyle}, rankNumber{theRank}, zDepth{theRank}, board{theBoard}
{
    center = style->getBoardCenter();
}
    
Rank::~Rank()
{

}

sf::FloatRect Rank::getRect()
{
    sf::Vector2f widthHeight { width(), height() };    
    sf::FloatRect boundaries {topLeft(), widthHeight};
    return boundaries;
}

void Rank::highlight(Model::Position position, Highlight type)
{
    if (position.getRank() == rankNumber)
    {
	for (Field& field : drawableFields)
	{
	    if (field.getPosition() == position)
	    {
		switch (type)
		{
		    case Highlight::Cursor:
			field.setUnderCursor(); break;
		    case Highlight::Touched:	
			field.setTouched(); break;
		    case Highlight::PossibleMove:
			field.setHighlighted(); break;
		}
		break; // out of the for loop
	    }
	}
    }
}

void Rank::setZoomLevel(double theZoomLevel)
{
    zoomLevel = theZoomLevel;
}

void Rank::update()
{   
    if (!isVisible()) return;
    
    drawableFields.clear();
    center = style->getBoardCenter();
    buildRank();
    // highlight fields after this !
}

void Rank::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (!isVisible()) return;
    
    drawRankDecoration(target, topLeft());
    
    for (auto& field : drawableFields)
    {
	target.draw(field);
    }   
}

void Rank::buildRank()
{   
    for (int j = 0; j != 5; ++j)
    {
	currentRow = j;
	sf::Vector2f position(topLeft() + sf::Vector2f(0.f, scaleFactor() * j * style->getFieldSize()));
	buildRow(position);
    }
}

void Rank::buildRow(sf::Vector2f thePosition)
{    
    for (int k = 0; k != 5; ++k)
    {
	currentColumn = k;
	sf::Vector2f position(thePosition + sf::Vector2f(scaleFactor() * k * style->getFieldSize(), 0.f));
	Model::Position placeOnBoard { 4 - currentRow , currentColumn, rankNumber };
		
	const Model::PointerToPiece content {board->getPiece(placeOnBoard)};

	drawableFields.emplace_back(position, scaleFactor(), style, content, placeOnBoard);
    }
}

void Rank::drawRankDecoration(sf::RenderTarget& target, sf::Vector2f thePosition) const
{
    // draw notation to the upper left corner
    sf::Text notation(style->ZNotation[rankNumber], style->fontManager->font, scaleFactor() * style->getFontSize());
    sf::Color numberColor { sf::Color::Yellow };
    numberColor.a *= scaleFactor();
    notation.setColor(numberColor);
    notation.setStyle(sf::Text::Bold);
    notation.setPosition(thePosition + scaleFactor() * style->getUpperLeftNotationPosition());
    target.draw(notation);

    if (false) 
    {
	for (int j = 0; j != 5; ++j)
	{
	    sf::Vector2f position(thePosition + sf::Vector2f(0.f, scaleFactor() * j * style->getFieldSize()));
	    drawRowDecoration(target, position, j);
	}

	// draw notation under the plane
	sf::Color letterColor { sf::Color::Red };
	letterColor.a *= scaleFactor();
	notation.setColor(letterColor);
	notation.setStyle(sf::Text::Regular);
	for (int i = 0; i != 5; ++i)
	{
	    notation.setString(style->XNotation[i]);
	    sf::Vector2f offset { thePosition.x + i * style->getFieldSize(), thePosition.y };
	    sf::Vector2f topLeft { offset + style->getBottomNotationPosition() };
	    notation.setPosition(scaleFactor() * topLeft);
	    target.draw(notation);
	}    
    }
}

void Rank::drawRowDecoration(sf::RenderTarget& target, sf::Vector2f thePosition, int row) const
{
    // draw notation beside the plane
    sf::Text notation(style->YNotation[4 - row], style->fontManager->font, scaleFactor() * style->getFontSize());
    sf::Color letterColor { sf::Color::Red };
    letterColor.a *= scaleFactor();
    notation.setColor(letterColor);
    notation.setPosition(thePosition + scaleFactor() * style->getLeftNotationPosition());
    target.draw(notation);
}

Model::Position Rank::getFieldPositionFromScreenPosition(sf::Vector2f screenPosition)
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

bool Rank::isVisible() const
{
    return zDepth - zoomLevel >= 0;
}

bool Rank::isClosestToViewer() const
{
    double rankDepth = zDepth - zoomLevel;
    return 0 <= rankDepth && rankDepth < 1;
}

sf::Vector2f Rank::topLeft() const
{
    float xOffset { width() / 2.0f };
    float yOffset { height() / 2.0f };
    return center - sf::Vector2f(xOffset, yOffset);
}

float Rank::scaleFactor() const
{
    return pow(style->SCALEFACTOR, zDepth - zoomLevel);
}

float Rank::width() const
{
    return style->getBoardSize() * scaleFactor();
}

float Rank::height() const
{
    return style->getBoardSize() * scaleFactor();
}


}