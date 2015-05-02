#ifndef VIEW_FIELD_H
#define VIEW_FIELD_H

#include <SFML/Graphics/Drawable.hpp>
#include "Model/field.h"
#include "Model/position.h"
#include "View/stylesheet.h"

namespace View {
    
class Field : public sf::Drawable
{
    sf::Vector2f topLeft;
    StyleSheet *style;
    Model::Field content;
    bool underCursor { false };
    bool touched { false };
    bool highlighted { false };
public:
    Field(const sf::Vector2f &theTopLeft, StyleSheet *theStyle, const Model::Field &theContent);
    ~Field();
    sf::FloatRect getBoundaries();
    Model::Position getPosition() { return content.position; }
    void setUnderCursor();
    void notUnderCursor();
    void setTouched();
    void notTouched();
    void setHighlighted();
    void notHighlighted();
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    static bool isWhiteField(const Model::Position& position);
};

}
#endif // VIEW_FIELD_H
