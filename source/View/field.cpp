// (C) Máté Gergely - gerymate@gmail.com
#include "field.h"
#include "Model/piece.h"

namespace View {

Field::Field(const sf::Vector2f& theTopLeft, const float& theScaleFactor, StyleSheet* theStyle, 
	     const Model::PointerToPiece theContent, const Model::Position thePosition) 
    : topLeft(theTopLeft), scaleFactor(theScaleFactor), style(theStyle), content(theContent, thePosition)
{
}
    
Field::~Field()
{

}

sf::FloatRect Field::getBoundaries()
{
    sf::Vector2f fieldSize {style->getFieldSize(), style->getFieldSize()};
    sf::FloatRect boundaries {topLeft, scaleFactor * fieldSize};
    return boundaries;
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::Vector2f fieldSize {style->getFieldSize(), style->getFieldSize()};
    sf::RectangleShape fieldShape(scaleFactor * fieldSize);
    fieldShape.setPosition(topLeft);
    sf::Color backgroundColor = (isWhiteField(content.position)) ?
	style->WhiteFieldColor : style->BlackFieldColor;
    backgroundColor.a = 96; // magic constants forever!
    if (underCursor || touched || highlighted) {
	if (underCursor) backgroundColor *= style->CursorHighlightColor;
	if (touched) backgroundColor *= style->TouchHighlightColor;
	if (highlighted) backgroundColor *= style->HighlightColor;
	backgroundColor.a = 192;
    }
    fieldShape.setFillColor(backgroundColor);

    target.draw(fieldShape, states);  

    // also draw figure!
  
    if (content.owner != 0)
    {
	sf::RectangleShape figureImage(scaleFactor * fieldSize);
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