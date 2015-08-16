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
    sf::Vector2f center;
    StyleSheet *style;
    int rankNumber;
    int zDepth;
    double zoomLevel {0};
    Model::IBoardInfo* board;
    std::vector<Field> drawableFields;
        
    int currentRow, currentColumn;
    
public:
    Rank(StyleSheet *theStyle, int theRank, Model::IBoardInfo* theBoard);
    ~Rank();
    sf::FloatRect getRect();
    int getRankNumber() { return rankNumber; }
    void highlight(Model::Position position, Highlight type);
    void setZoomLevel(double theZoomLevel);
    void update();
    Model::Position getFieldPositionFromScreenPosition(sf::Vector2f screenPosition);
    bool isVisible() const;
    bool isClosestToViewer() const;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    void buildRank();
    void buildRow(sf::Vector2f thePosition);
    void drawRankDecoration(sf::RenderTarget& target, sf::Vector2f thePosition) const;
    void drawRowDecoration(sf::RenderTarget& target, sf::Vector2f thePosition, int row) const;
public: // for test purposes
    sf::Vector2f topLeft() const;
    float scaleFactor() const;
    float width() const;
    float height() const;
};

}
#endif // RANK_H
