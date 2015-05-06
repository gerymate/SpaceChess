#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include "View/widget.h"
#include <string>

namespace View {

class MessageWidget : public Widget
{
    std::string message {""};
    const int MAXCHARS {125};
public:
    MessageWidget(const sf::Vector2f& thePosition, StyleSheet* theStyle, std::string theMessage);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getRect() const override;
};

}

#endif // MESSAGEWIDGET_H
