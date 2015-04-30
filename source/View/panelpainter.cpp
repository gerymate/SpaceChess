#include "panelpainter.h"

namespace View {

PanelPainter::PanelPainter(sf::RenderTarget* theCanvas, StyleSheet* theStyleSheet)
    : canvas(theCanvas), style(theStyleSheet)
{
}

void PanelPainter::setGameState(const Model::GameState* theGameState)
{
    gameState = theGameState;
}

void PanelPainter::setCursorInfo(const Model::Coord* theCursor)
{
    cursor = theCursor;
}

void PanelPainter::draw()
{
    panel.clear();

    buildPanel(topLeft);

    for (auto& widget : panel)
    {
	canvas->draw(*widget);
    }
}

sf::FloatRect PanelPainter::getRect() const
{
    float top, maxRight, maxBottom, left;
    maxBottom = top = topLeft.y;
    maxRight = left = topLeft.x;    
    
    for (auto widget : panel)
    {
	sf::FloatRect boundaries = widget->getRect();
	float bottom = boundaries.top + boundaries.height;
	float right = boundaries.left + boundaries.width;
	if (bottom > maxBottom) maxBottom = bottom;
	if (right > maxRight) maxRight = right;
    }
    
    sf::Vector2f size {maxRight - left, maxBottom - top};
    return sf::FloatRect { topLeft, size };
}


void PanelPainter::buildPanel(sf::Vector2f thePosition)
{
    sf::Vector2f position = thePosition;
    std::shared_ptr<Widget> nextPlayerInfoWidget (new NextPlayerInfo (position, style, gameState->nextPlayer));
    panel.push_back(nextPlayerInfoWidget);
    
    position += sf::Vector2f(200, 0);
    std::shared_ptr<Widget> cursorInfoWidget (new CursorInfo (position, style, *cursor) );
    panel.push_back(cursorInfoWidget);

}


}