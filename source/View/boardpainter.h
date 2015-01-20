#ifndef BOARDPAINTER_H
#define BOARDPAINTER_H

#include <SFML/Graphics.hpp>
#include "../Model/board.h"

class BoardPainter
{
  sf::RenderTarget* canvas;
  Board* board;
  int currentPlane;
  int currentRow;
  int currentColumn;
  std::vector<std::vector<sf::Texture> > pieces;
  
  // our layout constants are in pixels for now
  const int MARGINSIZE = 30;
  const int FIELDSIZE = 40;
  const int PLANESIZE = FIELDSIZE * 5; // 5 is number of fields in a row
  
public:
  BoardPainter(sf::RenderTarget* theCanvas, Board* theBoard=nullptr);
  void setBoard(Board* theBoard);
  void draw();
private:
  void drawPlane(sf::Vector2f thePosition);
  void drawRow(sf::Vector2f thePosition);
  void drawField(sf::Vector2f thePosition);
  
};

#endif // BOARDPAINTER_H
