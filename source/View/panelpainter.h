#ifndef PANELPAINTER_H
#define PANELPAINTER_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "View/stylesheet.h"
#include "Model/gamestate.h"
#include "View/widget.h"
#include "View/cursorinfo.h"

namespace View {

class PanelPainter
{
    sf::RenderTarget* canvas;
    StyleSheet* style;
    const Model::GameState* gameState;
    const Model::Coord* cursor;
    std::vector< std::shared_ptr<Widget> > panel;
public:
    PanelPainter(sf::RenderTarget* theCanvas, StyleSheet* theStyleSheet);
    void setGameState(const Model::GameState* theGameState);
    void draw(sf::Vector2f thePosition = sf::Vector2f(0, 0));
    void setCursorInfo(const Model::Coord* theCursor);
private:
    void buildPanel(sf::Vector2f thePosition);
};

}
#endif // PANELPAINTER_H
