#ifndef GAMEEVENT_H
#define GAMEEVENT_H

#include <string>
#include "common.h"
#include "player.h"
#include "game.h"
#include "history.h"
#include "judge.h"

namespace Model
{
    
class GameEvent
{
    static PointerToGameEvent generateMoveFromString(const std::string& moveDesc, Game* theGame);
    static bool isPromotion(const Position& from, const Position& to, Game* theGame);
public:
    static PointerToGameEvent generateMove(const std::string& moveDesc, Game* theGame);
    static PointerToGameEvent generateMove(const Position& from, const Position& to, Game* theGame);

    GameEvent(Game* theGame = nullptr);
    void setGame(Game* theGame);
    virtual bool execute() = 0;
    virtual bool revert() = 0;
    virtual std::string getNotation() const = 0;
    Player getPlayer() const;
    int getMoveNumber() const;
    virtual ~GameEvent();

    friend std::ostream& operator<<(std::ostream& outputStream, const Model::GameEvent& gameEvent);
protected:
    Game *game { nullptr };

    Player player { Player::Nobody };
    int moveNumber { 0 };

    void setPlayerAndMoveNumberBasedOnPreviousGameEvent();
    
};

}
#endif // GAMEEVENT_H
