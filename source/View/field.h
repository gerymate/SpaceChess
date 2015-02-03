#ifndef VIEW_FIELD_H
#define VIEW_FIELD_H

#include <SFML/Graphics/Drawable.hpp>
#include "Model/field.h"
#include "Model/coord.h"
#include "View/stylesheet.h"

namespace View {

class Field : public sf::Drawable
{
    sf::Vector2f topLeft;
    StyleSheet *style;
    Model::Field content;
public:
    Field(const sf::Vector2f &theTopLeft, StyleSheet *theStyle, const Model::Field &theContent);
    ~Field();
    sf::FloatRect getBoundaries();
    Model::Coord getCoord();
protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}
#endif // VIEW_FIELD_H
