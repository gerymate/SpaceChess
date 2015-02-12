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


void PanelPainter::draw(sf::Vector2f thePosition)
{
    panel.clear();

    buildPanel(thePosition);

    for (auto& widget : panel)
    {
	canvas->draw(*widget);
    }
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