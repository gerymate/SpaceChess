// (C) Máté Gergely - gerymate@gmail.com
#ifndef VIEW_FIELD_H
#define VIEW_FIELD_H

#include <SFML/Graphics/Drawable.hpp>
#include "common.h"
#include "Model/position.h"
#include "stylesheet.h"
#include "fieldcontent.h"

namespace View {
    
class Field : public sf::Drawable
{
    sf::Vector2f topLeft;
    float scaleFactor;
    StyleSheet *style;
    FieldContent content;
    bool underCursor { false };
    bool touched { false };
    bool highlighted { false };
public:
    Field(const sf::Vector2f &theTopLeft, const float& theScaleFactor, StyleSheet *theStyle, 
	  const Model::PointerToPiece theContent, const Model::Position thePosition = Model::Position());
    ~Field();
    sf::FloatRect getBoundaries();
    Model::Position getPosition();
    void setUnderCursor();
    void notUnderCursor();
    bool isUnderCursor(); // for testing purposes
    void setTouched();
    void notTouched();
    void setHighlighted();
    void notHighlighted();
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    static bool isWhiteField(const Model::Position& position);
};

}
#endif // VIEW_FIELD_H
