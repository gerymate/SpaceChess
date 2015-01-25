#include "boardpainter.h"

using namespace Model;

namespace View {

BoardPainter::BoardPainter(sf::RenderTarget* theCanvas, Model::Board* theBoard) : canvas(theCanvas), board(theBoard)
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
    
    // load font
    if (! font.loadFromFile("sansation.ttf"))
    {
	std::cerr << "Error loading sansation.ttf" << std::endl;
    }
}

void BoardPainter::setBoard(Model::Board* theBoard)
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
    // draw notation to the upper left corner
    sf::Text notation(largeNotation[currentPlane], font, 0.5f * MARGINSIZE);
    notation.setColor(sf::Color::Yellow);
    notation.setStyle(sf::Text::Bold);
    notation.setPosition(thePosition + sf::Vector2f(-0.4f * MARGINSIZE, -0.6f * MARGINSIZE));
    canvas->draw(notation);
    
    // draw the plane
    for (int j = 0; j != 5; ++j)
    {
	currentRow = j;
	sf::Vector2f position(thePosition + sf::Vector2f(0.f, j * FIELDSIZE));
	drawRow(position);
    }

    // draw notation under the plane
    notation.setColor(sf::Color::Red);
    notation.setStyle(sf::Text::Regular);
    for (int i = 0; i != 5; ++i)
    {
	notation.setString(smallNotation[i]);
	sf::Vector2f offset(thePosition.x + i * FIELDSIZE, thePosition.y);
	notation.setPosition(offset + sf::Vector2f(0.4f * FIELDSIZE, 5.f * FIELDSIZE));
	canvas->draw(notation);
    }    
}

void BoardPainter::drawRow(sf::Vector2f thePosition)
{
    // draw notation beside the plane
    sf::Text notation(digitNotation[4 - currentRow], font, 0.5f * MARGINSIZE);
    notation.setColor(sf::Color::Red);
    notation.setPosition(thePosition + sf::Vector2f(-0.5f * MARGINSIZE, 1.f * (FIELDSIZE - MARGINSIZE)));
    canvas->draw(notation);
   
    // draw the row
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

}