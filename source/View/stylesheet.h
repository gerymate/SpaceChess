// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#ifndef STYLESHEET_H
#define STYLESHEET_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

namespace View {

struct StyleSheet
{
    std::vector<std::vector<sf::Texture> > pieces;
    sf::Font font;
	const std::string XNotation = std::string{ "abcde" };
	const std::string YNotation = std::string{ "ABCDE" };
	const std::string ZNotation = std::string{ "12345" };
  
    // our layout constants are in pixels for now
    const float MARGINSIZE = 30.f;
    const float FIELDSIZE = 40.f;
    const sf::Vector2f FieldSize {FIELDSIZE, FIELDSIZE};
    const int PLANESIZE = FIELDSIZE * 5; // 5 is number of fields in a row
    const int FONTSIZE = 0.5f * MARGINSIZE;
    const int BOARDHEIGHT = 300; // warning! estimation!

    const sf::Color WhiteFieldColor {255, 255, 255};
    const sf::Color BlackFieldColor {150, 150, 150};
    const sf::Color CursorHighlightColor {128, 255, 128};
    const sf::Color TouchHighlightColor {0, 128, 255};
    const sf::Color HighlightColor {255, 128, 200};
public:
    StyleSheet();
    ~StyleSheet();
    const sf::Texture* getPieceFor(int owner, int figure) const;
};

}

#endif // STYLESHEET_H
