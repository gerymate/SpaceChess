#ifndef GAME_H
#define GAME_H

#include "common.h"
#include "igameinfo.h"
#include "figure.h"

namespace Model {
//	A Game is a full abstraction of a single SpaceChess game

class Game : public IGameInfo
{
    Board* board;
    History* history;
    Judge* judge;
    bool ended{false};

public:
    Game();
    ~Game();
    
    std::string move(Position& from, Position& to);
    std::string move(Position& from, Position& to, Figure promoteTo);
    std::string stepForward();
    std::string stepBackward();

    GameState getGameState() const override;
    PointerToPositionList getCurrentlyPossibleMovesFrom(Position& from) const override;
    Player getNextPlayer() const override;
    Board* getBoard() const override;
    History* getHistory() const override;
    Judge* getJudge() const override;
    
    friend std::ostream& operator<<(std::ostream& outputStream, const Model::Game& game);
    friend std::istream& operator>>(std::istream& inputStream, Model::Game& game);
};

}

#endif
