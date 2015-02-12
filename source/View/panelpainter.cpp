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
    std::shared_ptr<Widget> cursorInfoWidget (new CursorInfo (thePosition, style, *cursor) );
    panel.push_back(cursorInfoWidget);

}


}