#include "field.h"

namespace View {

Field::Field(const sf::Vector2f& theTopLeft, StyleSheet *theStyle, const Model::Field& theContent) 
    : topLeft(theTopLeft), style(theStyle), content(theContent)
{

}
    
Field::~Field()
{

}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::RectangleShape fieldShape(style->FieldSize);
    fieldShape.setPosition(topLeft);
    if (content.place.getColour() == Model::Coord::BLACK)
    {
	fieldShape.setFillColor(style->BlackFieldColor);
    } else {
	fieldShape.setFillColor(style->WhiteFieldColor);
    }

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

}