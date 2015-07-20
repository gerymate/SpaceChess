// (C) Máté Gergely - gerymate@gmail.com
#ifndef RANK_H
#define RANK_H

#include <SFML/Graphics/Drawable.hpp>
#include "Model/field.h"
#include "field.h"
#include "Model/position.h"
#include "stylesheet.h"
#include "Model/iboardinfo.h"

namespace View {
    
enum class Highlight { Cursor, Touched, PossibleMove };
    
class Rank : public sf::Drawable
{
    sf::Vector2f topLeft;
    StyleSheet *style;
    int rank;
    Model::IBoardInfo* board;
    std::vector<Field> drawableFields;
        
    int currentRow, currentColumn;
    
public:
    Rank(const sf::Vector2f &theTopLeft, StyleSheet *theStyle, int theRank, Model::IBoardInfo* theBoard);
    ~Rank();
    sf::FloatRect getBoundaries();
    int getRank() { return rank; }
    void highlight(Model::Position position, Highlight type);
    void update(sf::Vector2f thePosition);
    Model::Position getFieldPositionFromScreenPosition(sf::Vector2f screenPosition);
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    void buildRank(sf::Vector2f thePosition);
    void buildRow(sf::Vector2f thePosition);
    void drawRankDecoration(sf::RenderTarget& target, sf::Vector2f thePosition) const;
    void drawRowDecoration(sf::RenderTarget& target, sf::Vector2f thePosition, int row) const;
};

}
#endif // RANK_H
