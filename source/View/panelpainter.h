#ifndef PANELPAINTER_H
#define PANELPAINTER_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "View/stylesheet.h"
#include "Model/gamestate.h"
#include "View/widget.h"
#include "View/cursorinfo.h"
#include "View/nextplayerinfo.h"

namespace View {

class PanelPainter
{
    sf::RenderTarget* canvas;
    StyleSheet* style;
    const Model::GameState* gameState;
    const Model::Coord* cursor;
    std::vector< std::shared_ptr<Widget> > panel;
    sf::Vector2f topLeft {0, 0};
public:
    PanelPainter(sf::RenderTarget* theCanvas, StyleSheet* theStyleSheet);
    void setGameState(const Model::GameState* theGameState);
    void draw();
    void setTopLeft(sf::Vector2f theTopLeft) { topLeft = theTopLeft; }
    void setCursorInfo(const Model::Coord* theCursor);
    sf::FloatRect getRect() const;
    void handleClick(sf::Vector2f &mousePosition) {}

private:
    void buildPanel(sf::Vector2f thePosition);
};

}
#endif // PANELPAINTER_H
