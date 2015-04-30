#ifndef BOARDPAINTER_H
#define BOARDPAINTER_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "common.h"
#include "event.h"
#include "Model/game.h"
#include "Model/gamestate.h"
#include "Model/fullboard.h"
#include "View/stylesheet.h"
#include "View/field.h"

namespace View {

class BoardPainter
{
  sf::RenderTarget* canvas;
  StyleSheet* style;
  Model::Game* game;
  EventQueue* eventQueue;
  const Model::FullBoard* board;
  const Model::GameState* gameState;
  int currentPlane;
  int currentRow;
  int currentColumn;
  std::vector<Field> drawableFields;
  Model::Coord cursor {-1, -1, -1};
  sf::Vector2f topLeft {0, 0};
  Model::Position selectedField {Model::Position::Invalid};

public:
  BoardPainter(sf::RenderTarget* theCanvas, StyleSheet* theStyleSheet, 
	       Model::Game* theGame, EventQueue* theEventQueue);
  void setGameState(const Model::GameState* theGameState);
  void setTopLeft(sf::Vector2f theTopLeft) { topLeft = theTopLeft; }
  void draw();
  sf::FloatRect getRect() const;
  void handleClick(sf::Vector2f &mousePosition);
  void setSelectedField(Model::Position theSelectedField) { selectedField = theSelectedField; }
  void clearSelectedField() { selectedField = Model::Position::Invalid; }


  Model::Coord getFieldCoordByPosition(sf::Vector2f position);
  Model::Coord setAndGetCursorByPosition(sf::Vector2f position);

private:
  void buildPlane(sf::Vector2f thePosition);
  void buildRow(sf::Vector2f thePosition);
  void drawRowDecoration(sf::Vector2f thePosition);
  void drawPlaneDecoration(sf::Vector2f thePosition);
  void highlightFieldUnderCursor();
  void highlightTouchedField();
  
};

}

#endif // BOARDPAINTER_H
