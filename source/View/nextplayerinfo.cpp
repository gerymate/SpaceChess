#include "nextplayerinfo.h"
#include <string>

namespace View {
 
NextPlayerInfo::NextPlayerInfo(const sf::Vector2f& thePosition, StyleSheet* theStyle, Model::Player theNextPlayer)
    : Widget(thePosition, theStyle), nextPlayer(theNextPlayer)
{
}

void NextPlayerInfo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    std::string nextPlayerText {"Game Over"};
    if (nextPlayer == Model::Player::White) nextPlayerText = "White to move";
    if (nextPlayer == Model::Player::Black) nextPlayerText = "Black to move";

    sf::Text cursorInfo(nextPlayerText, style->font, style->FONTSIZE);
    cursorInfo.setColor(sf::Color::Yellow);
    cursorInfo.setStyle(sf::Text::Bold);
    cursorInfo.setPosition(position);
    target.draw(cursorInfo);
}
    
}