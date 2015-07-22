// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "field.h"
#include "Model/Pieces/piece.h"

namespace View {

Field::Field(const sf::Vector2f& theTopLeft, StyleSheet* theStyle, 
	     const Model::PointerToPiece theContent, const Model::Position thePosition) 
    : topLeft(theTopLeft), style(theStyle), content(theContent, thePosition)
{
}
    
Field::~Field()
{

}

sf::FloatRect Field::getBoundaries()
{
    sf::FloatRect boundaries {topLeft, style->FieldSize};
    return boundaries;
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::RectangleShape fieldShape(style->FieldSize);
    fieldShape.setPosition(topLeft);
    sf::Color backgroundColor = (isWhiteField(content.position)) ?
	style->WhiteFieldColor : style->BlackFieldColor;
    if (underCursor) backgroundColor *= style->CursorHighlightColor;
    if (touched) backgroundColor *= style->TouchHighlightColor;
    if (highlighted) backgroundColor *= style->HighlightColor;
    fieldShape.setFillColor(backgroundColor);

    target.draw(fieldShape, states);  

    // also draw figure!
  
    if (content.owner != 0)
    {
	sf::RectangleShape figureImage(style->FieldSize);
	figureImage.setPosition(topLeft);
	figureImage.setTexture(style->textureManager->getPieceFor(content.owner, static_cast<int>(content.figure)));
	target.draw(figureImage, states);
    }
}

void Field::setTouched()
{
    touched = true;
}

void Field::notTouched()
{
    touched = false;
}

void Field::setUnderCursor()
{
    underCursor = true;
}

void Field::notUnderCursor()
{
    underCursor = false;
}

bool Field::isUnderCursor()
{
    return underCursor;
}


void Field::setHighlighted()
{
    highlighted = true;
}

void Field::notHighlighted()
{
    highlighted = false;
}

bool Field::isWhiteField(const Model::Position& position)
{
    return ((position.getFile() + position.getLevel() + position.getRank()) % 2);
}

Model::Position Field::getPosition()
{
    return content.position;
}





}