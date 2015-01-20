#include "boardpainter.h"

/*
 sf::RenderTarget* canvas;
GameState* board;
int currentPlane;
int currentRow;
int currentColumn;
*/

BoardPainter::BoardPainter(sf::RenderTarget* theCanvas, Board* theBoard) : canvas(theCanvas), board(theBoard)
{
    // load pieces!
    pieces.resize(2);
    pieces[0].resize(7);
    pieces[1].resize(7);
    std::vector<std::vector<std::string> > fileNames {
	{"white-king.png", "white-queen.png", "white-rook.png", "white-bishop.png", "white-knight.png", "white-unicorn.png", "white-pawn.png"},
	{"black-king.png", "black-queen.png", "black-rook.png", "black-bishop.png", "black-knight.png", "black-unicorn.png", "black-pawn.png"},
    };

    for (int i = 0; i != 2; ++i)
    {
	for (int j = 0; j != 7; ++j)
	{
	    if (! (pieces[i][j]).loadFromFile(fileNames[i][j]))
	    {
		std::cerr << "Error loading " << fileNames[i][j] << std::endl;
	    }
	}
    }
   
    //    	int owner;	// 0..2
	/* 0 - noone
	 * 1 - white
	 * 2 - black
	*/
//	int figure;	// 0..7 should be an enum?
	/* 0 - none
	 * 1 - king
	 * 2 - queen
	 * 3 - rook
	 * 4 - bishop
	 * 5 - knight
	 * 6 - unicorn
	 * 7 - pawn
	*/
}

void BoardPainter::setBoard(Board* theBoard)
{
    board = theBoard;
}

void BoardPainter::draw()
{
  for (int i = 0; i != 5; ++i)
  {
    currentPlane = i;
    float xOffset = MARGINSIZE + i * (MARGINSIZE + PLANESIZE);
    sf::Vector2f position(xOffset, MARGINSIZE);
    drawPlane(position);
  }
}

void BoardPainter::drawPlane(sf::Vector2f thePosition)
{
  for (int j = 0; j != 5; ++j)
  {
    currentRow = j;
    sf::Vector2f position(thePosition + sf::Vector2f(0.f, j * FIELDSIZE));
    drawRow(position);
  }
}

void BoardPainter::drawRow(sf::Vector2f thePosition)
{
  for (int k = 0; k != 5; ++k)
  {
    currentColumn = k;
    sf::Vector2f position(thePosition + sf::Vector2f(k * FIELDSIZE, 0.f));
    drawField(position);
  }
}

void BoardPainter::drawField(sf::Vector2f thePosition)
{
    sf::RectangleShape fieldShape(sf::Vector2f(FIELDSIZE, FIELDSIZE));
    fieldShape.setPosition(thePosition);
    const Field field {board->space[currentPlane][currentColumn][4 - currentRow]};
    if (field.place.getColour() == Coord::BLACK)
    {
	fieldShape.setFillColor(sf::Color{100, 100, 100});
    } else {
	fieldShape.setFillColor(sf::Color{230, 230, 230});
    }

    canvas->draw(fieldShape);  

    // also draw figure!
  
    if (field.owner != 0)
    {
	sf::RectangleShape figure(sf::Vector2f(FIELDSIZE, FIELDSIZE));
	figure.setPosition(thePosition);
	figure.setTexture(&pieces[field.owner - 1][field.figure - 1]);
	canvas->draw(figure);
    }
}

