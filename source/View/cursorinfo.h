#ifndef CURSORINFO_H
#define CURSORINFO_H

#include "View/widget.h"
#include "Model/position.h"

namespace View {

class CursorInfo : public Widget
{
    Model::Position cursor;
public:
    CursorInfo(const sf::Vector2f& thePosition, StyleSheet* theStyle, Model::Position theCursor);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getRect() const override;
};

}

#endif // CURSORINFO_H
