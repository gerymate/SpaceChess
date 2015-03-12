#ifndef BOARDPAINTER_H
#define BOARDPAINTER_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Model/gamestate.h"
#include "Model/board.h"
#include "View/stylesheet.h"
#include "View/field.h"

namespace View {

class BoardPainter
{
  sf::RenderTarget* canvas;
  StyleSheet* style;
  const Model::Board* board;
  const Model::GameState* gameState;
  int currentPlane;
  int currentRow;
  int currentColumn;
  std::vector<Field> drawableFields;
  Model::Coord cursor {-1, -1, -1};

public:
  BoardPainter(sf::RenderTarget* theCanvas, StyleSheet* theStyleSheet);
  void setGameState(const Model::GameState* theGameState);
  void draw(sf::Vector2f thePosition = sf::Vector2f(0, 0));

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
