// (C) Máté Gergely - gerymate@gmail.com
#include "stylesheet.h"

#include <iostream>

namespace View {


StyleSheet::StyleSheet(TextureManager* theTextureManager, FontManager* theFontManager) 
    : textureManager{ theTextureManager }, fontManager{ theFontManager }
{
}

void StyleSheet::setBoardSize(float newBoardSize)
{
    boardSize = newBoardSize;
}

float StyleSheet::getBoardSize() const
{
    return boardSize;
}

float StyleSheet::getFieldSize() const
{
    return boardSize / NUMBEROFFIELDSINAROW;
}

float StyleSheet::getMarginSize() const
{
    return _MARGINSIZE * getViewPortScale();
}

float StyleSheet::getViewPortScale() const
{
    return boardSize / _PLANESIZE;
}

sf::Vector2f StyleSheet::getUpperLeftNotationPosition() const
{
    return sf::Vector2f { -0.4f * getMarginSize(), -0.6f * getMarginSize() };
}

sf::Vector2f StyleSheet::getLeftNotationPosition() const
{
    return sf::Vector2f { -0.5f * getMarginSize(), getFieldSize() - getMarginSize() };
}

sf::Vector2f StyleSheet::getBottomNotationPosition() const
{
    return sf::Vector2f { 0.4f * getFieldSize(), 5.0f * getFieldSize() };
}

sf::Vector2f StyleSheet::getBoardTopLeft() const
{
    return boardTopLeft;
}

sf::Vector2f StyleSheet::getBoardCenter() const
{
    return sf::Vector2f { boardTopLeft.x + getMarginSize() + getBoardSize() / 2, 
			  boardTopLeft.y + getMarginSize() + getBoardSize() / 2 };
}

int StyleSheet::getFontSize() const
{
    return 0.5f * getMarginSize();
}


StyleSheet::~StyleSheet()
{

}


}