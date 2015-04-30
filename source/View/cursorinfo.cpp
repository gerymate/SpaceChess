#include "cursorinfo.h"

namespace View {
 
CursorInfo::CursorInfo(const sf::Vector2f& thePosition, StyleSheet* theStyle, Model::Coord theCursor) 
    : Widget(thePosition, theStyle), cursor(theCursor)
{
}

void CursorInfo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::Text cursorInfo(cursor.getNotation(), style->font, style->FONTSIZE);
    cursorInfo.setColor(sf::Color::Yellow);
    cursorInfo.setStyle(sf::Text::Bold);
    cursorInfo.setPosition(position);
    target.draw(cursorInfo);
}
    
sf::FloatRect CursorInfo::getRect() const
{
    const int MAXCHARS = 10;
    sf::Vector2f size { (float)style->FONTSIZE * MAXCHARS, (float)style->FONTSIZE };
    return sf::FloatRect( position, size );
}

    
}