// (C) Máté Gergely - gerymate@gmail.com
#ifndef STYLESHEET_H
#define STYLESHEET_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "texturemanager.h"
#include "fontmanager.h"

namespace View {

struct StyleSheet
{
    const TextureManager* textureManager;
    const FontManager* fontManager;

    const std::string XNotation = std::string{ "abcde" };
    const std::string YNotation = std::string{ "ABCDE" };
    const std::string ZNotation = std::string{ "12345" };
  
    // our layout constants are in pixels for now
    const int NUMBEROFFIELDSINAROW = 5;
    const float _MARGINSIZE = 30.f;
    const float _FIELDSIZE = 40.f;
    const sf::Vector2f _FieldSize {_FIELDSIZE, _FIELDSIZE};
    const int _PLANESIZE = _FIELDSIZE * NUMBEROFFIELDSINAROW; // 5 is number of fields in a row
    const int FONTSIZE = 0.5f * _MARGINSIZE;
    const float SCALEFACTOR = 0.85f;
    const int BOARDHEIGHT = 300; // warning! estimation! use getBoardSize() instead! Unused at all?
    
    const sf::Color WhiteFieldColor {255, 255, 255};
    const sf::Color BlackFieldColor {150, 150, 150};
    const sf::Color CursorHighlightColor {96, 128, 96};
    const sf::Color TouchHighlightColor {0, 128, 255};
    const sf::Color HighlightColor {255, 128, 200};
    
private:
    float boardSize { 300 };
    sf::Vector2f boardTopLeft { 0.0f, 0.0f };
    
public:
    StyleSheet(TextureManager* theTextureManager, FontManager* theFontManager);
    void setBoardSize(float newBoardSize);
    float getBoardSize() const;
    float getFieldSize() const;
    float getMarginSize() const;
    float getViewPortScale() const;
    sf::Vector2f getUpperLeftNotationPosition() const;
    sf::Vector2f getLeftNotationPosition() const;
    sf::Vector2f getBottomNotationPosition() const;
    sf::Vector2f getBoardTopLeft() const;
    sf::Vector2f getBoardCenter() const;
    int getFontSize() const;
    
    ~StyleSheet();
};

}

#endif // STYLESHEET_H
