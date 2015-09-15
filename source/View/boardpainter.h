// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#ifndef BOARDPAINTER_H
#define BOARDPAINTER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "common.h"
#include "event.h"
#include "Model/igameinfo.h"
#include "stylesheet.h"
#include "field.h"
#include "rank.h"
#include "Util/timelychangingvalue.h"

namespace View {

class BoardPainter
{
    sf::RenderTarget* canvas;
    StyleSheet* style;
    Model::IGameInfo* game;
    EventQueue* eventQueue;
    Model::Player localPlayers {Model::Player::Both};
    const Model::FullBoard* board;
    const Model::GameState* gameState;
    int currentPlane;
    int currentRow;
    int currentColumn;
    static const int numberOfRanks;
    std::vector<Rank> drawableRanks;
    Model::Position cursor {Model::Position::Invalid};
    Model::Position selectedField {Model::Position::Invalid};
    Model::PointerToPositionList highlightedFields;
    const double MINZOOMLEVEL {0};
    const double MAXZOOMLEVEL {4};
    double targetZoomLevel {MINZOOMLEVEL};
    Util::TimelyChangingValue zoomLevel {targetZoomLevel};

public:
    BoardPainter(sf::RenderTarget* theCanvas, StyleSheet* theStyleSheet, 
		 Model::IGameInfo* theGame, EventQueue* theEventQueue);
    void setGameState(const Model::GameState* theGameState);
    void setLocalPlayers(Model::Player theLocalPlayers);
    void update();
    void draw();
    sf::FloatRect getRect() const;
    void handleClick(sf::Vector2f &mousePosition);
    void zoomIn();
    void zoomOut();
    void setSelectedField(Model::Position theSelectedField) { selectedField = theSelectedField; }
    void clearSelectedField() { selectedField = Model::Position::Invalid; }
    void setHighlightedFields(Model::PointerToPositionList thePositions) 
							{ highlightedFields = thePositions; }

    Model::Position getFieldPositionFromScreenPosition(sf::Vector2f screenPosition);
    Model::Position setAndGetBoardCursorFromScreenPosition(sf::Vector2f screenPosition);

private:
    void buildRanks();
    void highlightFieldUnderCursor();
    void highlightTouchedField(); 
    void highlightPossibleMoves();
    void drawBoardDecorations();
    void drawRowDecoration(sf::Vector2f thePosition, int row);

};

}

#endif // BOARDPAINTER_H
