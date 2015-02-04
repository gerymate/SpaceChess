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

Model::Coord Field::getCoord()
{
    return content.place;
}


void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::RectangleShape fieldShape(style->FieldSize);
    fieldShape.setPosition(topLeft);
    sf::Color backgroundColor = (content.place.getColour() == Model::Coord::BLACK) ?
	style->BlackFieldColor : style->WhiteFieldColor;
    if (highlight == 1) backgroundColor *= style->CursorHighlightColor;
    fieldShape.setFillColor(backgroundColor);

    target.draw(fieldShape, states);  

    // also draw figure!
  
    if (content.owner != 0)
    {
	sf::RectangleShape figure(style->FieldSize);
	figure.setPosition(topLeft);
	figure.setTexture(style->getPieceFor(content.owner, content.figure));
	target.draw(figure, states);
    }
}

void Field::setHighlight(int level)
{
    highlight = level;
}


}