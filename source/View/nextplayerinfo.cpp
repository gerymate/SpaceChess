// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "nextplayerinfo.h"
#include <string>

namespace View {
 
NextPlayerInfo::NextPlayerInfo(const sf::Vector2f& thePosition, StyleSheet* theStyle, 
			       Model::Player theNextPlayer, Model::Player theLocalPlayer)
    : Widget(thePosition, theStyle), nextPlayer(theNextPlayer), localPlayer(theLocalPlayer)
{
}

void NextPlayerInfo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    std::string nextPlayerText {"Game Over"};
    if (nextPlayer == Model::Player::White) nextPlayerText = "White to move.";
    if (nextPlayer == Model::Player::Black) nextPlayerText = "Black to move.";
    
    if (nextPlayerText.length() > (size_t)MAXCHARS) nextPlayerText.erase(MAXCHARS);

    sf::Text nextPlayerInfo(nextPlayerText, style->fontManager->font, style->FONTSIZE);
    nextPlayerInfo.setColor(sf::Color::Red);
    nextPlayerInfo.setStyle(sf::Text::Bold);
    nextPlayerInfo.setPosition(position);
    target.draw(nextPlayerInfo);
    
    if (localPlayer == Model::Player::White || localPlayer == Model::Player::Black)
    {
	std::string localPlayerText;
	if (localPlayer == Model::Player::White) localPlayerText = "You play White.";
	if (localPlayer == Model::Player::Black) localPlayerText = "You play Black.";

	sf::Text localPlayerInfo(localPlayerText, style->fontManager->font, style->FONTSIZE);
	localPlayerInfo.setColor(sf::Color::Yellow);
	localPlayerInfo.setStyle(sf::Text::Bold);
	sf::Vector2f offset {(MAXCHARS * (float)style->FONTSIZE) + 5 * style->MARGINSIZE, 0};
	localPlayerInfo.setPosition(position + offset);
	target.draw(localPlayerInfo);
    }
}

sf::FloatRect NextPlayerInfo::getRect() const
{
    sf::Vector2f size { (float)style->FONTSIZE * (MAXCHARS + 15) + 5 * style->MARGINSIZE, (float)style->FONTSIZE };
    return sf::FloatRect( position, size );
}

    
}