// (C) Máté Gergely - gerymate@gmail.com
#include "rank.h"

namespace View {

Rank::Rank(const sf::Vector2f& theCenter, StyleSheet *theStyle, int theRank, Model::IBoardInfo* theBoard) 
    : center{theCenter}, style{theStyle}, rankNumber{theRank}, zDepth{theRank}, board{theBoard}
{
}
    
Rank::~Rank()
{

}

sf::FloatRect Rank::getBoundaries()
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

void Rank::update()
{    
    drawableFields.clear();
    buildRank();
    // highlight fields after this !
}


void Rank::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    
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
	sf::Vector2f position(topLeft() + sf::Vector2f(0.f, scaleFactor() * j * style->FIELDSIZE));
	buildRow(position);
    }
}

void Rank::buildRow(sf::Vector2f thePosition)
{    
    for (int k = 0; k != 5; ++k)
    {
	currentColumn = k;
	sf::Vector2f position(thePosition + sf::Vector2f(scaleFactor() * k * style->FIELDSIZE, 0.f));
	Model::Position placeOnBoard { 4 - currentRow , currentColumn, rankNumber };
		
	const Model::PointerToPiece content {board->getPiece(placeOnBoard)};

	drawableFields.emplace_back(position, scaleFactor(), style, content, placeOnBoard);
    }
}

void Rank::drawRankDecoration(sf::RenderTarget& target, sf::Vector2f thePosition) const
{
    // draw notation to the upper left corner
    sf::Text notation(style->ZNotation[rankNumber], style->fontManager->font, 0.5f * style->MARGINSIZE);
    notation.setColor(sf::Color::Yellow);
    notation.setStyle(sf::Text::Bold);
    notation.setPosition(thePosition + sf::Vector2f(-0.4f * style->MARGINSIZE, -0.6f * style->MARGINSIZE));
    target.draw(notation);

    for (int j = 0; j != 5; ++j)
    {
	sf::Vector2f position(thePosition + sf::Vector2f(0.f, j * style->FIELDSIZE));
	drawRowDecoration(target, position, j);
    }

    // draw notation under the plane
    notation.setColor(sf::Color::Red);
    notation.setStyle(sf::Text::Regular);
    for (int i = 0; i != 5; ++i)
    {
	notation.setString(style->XNotation[i]);
	sf::Vector2f offset(thePosition.x + i * style->FIELDSIZE, thePosition.y);
	notation.setPosition(offset + sf::Vector2f(0.4f * style->FIELDSIZE, 5.f * style->FIELDSIZE));
	target.draw(notation);
    }    
}

void Rank::drawRowDecoration(sf::RenderTarget& target, sf::Vector2f thePosition, int row) const
{
    // draw notation beside the plane
    sf::Text notation(style->YNotation[4 - row], style->fontManager->font, 0.5f * style->MARGINSIZE);
    notation.setColor(sf::Color::Red);
    notation.setPosition(thePosition + sf::Vector2f(-0.5f * style->MARGINSIZE, 1.f * (style->FIELDSIZE - style->MARGINSIZE)));
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

sf::Vector2f Rank::topLeft() const
{
    return center - sf::Vector2f(width()/2.0, height()/2.0);
}

float Rank::scaleFactor() const
{
    return pow(style->SCALEFACTOR, zDepth);
}

float Rank::width() const
{
    return style->PLANESIZE * scaleFactor();
}

float Rank::height() const
{
    return style->PLANESIZE * scaleFactor();
}


}