#include "boardpainter.h"

namespace View {

BoardPainter::BoardPainter(sf::RenderTarget* theCanvas, Model::Board* theBoard) : canvas(theCanvas), board(theBoard)
{

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
	float xOffset = style.MARGINSIZE + i * (style.MARGINSIZE + style.PLANESIZE);
	sf::Vector2f position(xOffset, style.MARGINSIZE);
	drawPlane(position);
    }
    
    for (auto field : fields)
    {
	canvas->draw(field);
    }
    
}

void BoardPainter::drawPlane(sf::Vector2f thePosition)
{
    // draw notation to the upper left corner
    sf::Text notation(style.largeNotation[currentPlane], style.font, 0.5f * style.MARGINSIZE);
    notation.setColor(sf::Color::Yellow);
    notation.setStyle(sf::Text::Bold);
    notation.setPosition(thePosition + sf::Vector2f(-0.4f * style.MARGINSIZE, -0.6f * style.MARGINSIZE));
    canvas->draw(notation);
    
    // draw the plane
    for (int j = 0; j != 5; ++j)
    {
	currentRow = j;
	sf::Vector2f position(thePosition + sf::Vector2f(0.f, j * style.FIELDSIZE));
	buildRow(position);
	drawRowDecoration(position);
    }

    // draw notation under the plane
    notation.setColor(sf::Color::Red);
    notation.setStyle(sf::Text::Regular);
    for (int i = 0; i != 5; ++i)
    {
	notation.setString(style.smallNotation[i]);
	sf::Vector2f offset(thePosition.x + i * style.FIELDSIZE, thePosition.y);
	notation.setPosition(offset + sf::Vector2f(0.4f * style.FIELDSIZE, 5.f * style.FIELDSIZE));
	canvas->draw(notation);
    }    
}

void BoardPainter::buildRow(sf::Vector2f thePosition)
{    
    for (int k = 0; k != 5; ++k)
    {
	currentColumn = k;
	sf::Vector2f position(thePosition + sf::Vector2f(k * style.FIELDSIZE, 0.f));
	const Model::Field content {board->space[currentPlane][currentColumn][4 - currentRow]};
	fields.emplace_back(position, &style, content);
    }
}

void BoardPainter::drawRowDecoration(sf::Vector2f thePosition)
{
    // draw notation beside the plane
    sf::Text notation(style.digitNotation[4 - currentRow], style.font, 0.5f * style.MARGINSIZE);
    notation.setColor(sf::Color::Red);
    notation.setPosition(thePosition + sf::Vector2f(-0.5f * style.MARGINSIZE, 1.f * (style.FIELDSIZE - style.MARGINSIZE)));
    canvas->draw(notation);
}

Model::Coord BoardPainter::getCoordByPosition(sf::Vector2f position)
{
    Model::Coord cursor {0, 0, 0};
    return cursor;
}


}