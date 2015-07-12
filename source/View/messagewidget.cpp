// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "messagewidget.h"
#include <string>

namespace View {
 
MessageWidget::MessageWidget(const sf::Vector2f& thePosition, StyleSheet* theStyle, std::string theMessage)
    : Widget{thePosition, theStyle}, message(theMessage)
{
}

void MessageWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{   
    std::string message {MessageWidget::message};
    if (message.length() > (size_t)MAXCHARS) message.erase(MAXCHARS);

    sf::Text messageText(message, style->font, style->FONTSIZE);
    messageText.setColor(sf::Color::Yellow);
    messageText.setStyle(sf::Text::Bold);
    messageText.setPosition(position);
    target.draw(messageText);
}

sf::FloatRect MessageWidget::getRect() const
{
    sf::Vector2f size { (float)style->FONTSIZE * MAXCHARS, (float)style->FONTSIZE };
    return sf::FloatRect( position, size );
}

    
}