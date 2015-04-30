#ifndef WIDGET_H
#define WIDGET_H

#include <SFML/Graphics.hpp>
#include "stylesheet.h"

namespace View {

class Widget : public sf::Drawable
{
protected:
    sf::Vector2f position;
    StyleSheet* style;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
public:
    Widget(const sf::Vector2f &thePosition, StyleSheet *theStyle);
    virtual sf::FloatRect getRect() const = 0;
};

}

#endif // WIDGET_H
