#ifndef BOARDPAINTER_H
#define BOARDPAINTER_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Model/board.h"

namespace View {

class BoardPainter
{
  sf::RenderTarget* canvas;
  Model::Board* board;
  int currentPlane;
  int currentRow;
  int currentColumn;
  std::vector<std::vector<sf::Texture> > pieces;
  sf::Font font;
  const std::vector<std::string> smallNotation {"a", "b", "c", "d", "e"};
  const std::vector<std::string> largeNotation {"A", "B", "C", "D", "E"};
  const std::vector<std::string> digitNotation {"1", "2", "3", "4", "5"};
  
  // our layout constants are in pixels for now
  const int MARGINSIZE = 30;
  const int FIELDSIZE = 40;
  const int PLANESIZE = FIELDSIZE * 5; // 5 is number of fields in a row
  
public:
  BoardPainter(sf::RenderTarget* theCanvas, Model::Board* theBoard=nullptr);
  void setBoard(Model::Board* theBoard);
  void draw();
private:
  void drawPlane(sf::Vector2f thePosition);
  void drawRow(sf::Vector2f thePosition);
  void drawField(sf::Vector2f thePosition);
  
};

}

#endif // BOARDPAINTER_H
