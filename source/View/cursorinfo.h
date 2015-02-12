#ifndef CURSORINFO_H
#define CURSORINFO_H

#include "View/widget.h"
#include "Model/coord.h"

namespace View {

class CursorInfo : public Widget
{
    Model::Coord cursor;
public:
    CursorInfo(const sf::Vector2f& thePosition, StyleSheet* theStyle, Model::Coord theCursor);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}

#endif // CURSORINFO_H
