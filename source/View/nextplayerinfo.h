#ifndef NEXTPLAYERINFO_H
#define NEXTPLAYERINFO_H

#include "View/widget.h"
#include "Model/player.h"

namespace View {

class NextPlayerInfo : public Widget
{
    Model::Player nextPlayer;
    const int MAXCHARS {15};
public:
    NextPlayerInfo(const sf::Vector2f& thePosition, StyleSheet* theStyle, Model::Player theNextPlayer);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getRect() const override;
};

}

#endif // NEXTPLAYERINFO_H
