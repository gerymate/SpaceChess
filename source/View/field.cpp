#include "field.h"

namespace View {

Field::Field(const sf::Vector2f& theTopLeft, StyleSheet *theStyle, const Model::Field& theContent) 
    : topLeft(theTopLeft), style(theStyle), content(theContent)
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
	figureImage.setTexture(style->getPieceFor(content.owner, static_cast<int>(content.figure)));
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
    return !((position.getFile() + position.getLevel() + position.getRank()) % 2);
}





}