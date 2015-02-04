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
    const std::vector<std::string> smallNotation {"a", "b", "c", "d", "e"};
    const std::vector<std::string> largeNotation {"A", "B", "C", "D", "E"};
    const std::vector<std::string> digitNotation {"1", "2", "3", "4", "5"};
  
    // our layout constants are in pixels for now
    const float MARGINSIZE = 30.f;
    const float FIELDSIZE = 40.f;
    const sf::Vector2f FieldSize {FIELDSIZE, FIELDSIZE};
    const int PLANESIZE = FIELDSIZE * 5; // 5 is number of fields in a row

    const sf::Color WhiteFieldColor {230, 230, 230};
    const sf::Color BlackFieldColor {100, 100, 100};
    const sf::Color CursorHighlightColor {128, 255, 128};
    const sf::Color TouchHighlightColor {128, 128, 255};
public:
    StyleSheet();
    ~StyleSheet();
    const sf::Texture* getPieceFor(int owner, int figure) const;
};

}

#endif // STYLESHEET_H
