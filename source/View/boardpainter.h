#ifndef BOARDPAINTER_H
#define BOARDPAINTER_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Model/board.h"
#include "View/stylesheet.h"
#include "View/field.h"

namespace View {

class BoardPainter
{
  sf::RenderTarget* canvas;
  const Model::Board* board;
  int currentPlane;
  int currentRow;
  int currentColumn;
  StyleSheet style;
  std::vector<Field> drawableFields;
  Model::Coord cursor {-1, -1, -1};

public:
  BoardPainter(sf::RenderTarget* theCanvas, Model::Board* theBoard=nullptr);
  void setBoard(const Model::Board* theBoard);
  void draw();
  Model::Coord getCoordByPosition(sf::Vector2f position);
  Model::Coord setAndGetCursorByPosition(sf::Vector2f position);

private:
  void drawPlane(sf::Vector2f thePosition);
  void buildRow(sf::Vector2f thePosition);
  void drawRowDecoration(sf::Vector2f thePosition);
  void highlightFieldUnderCursor();
  
};

}

#endif // BOARDPAINTER_H
