#ifndef JUDGE_H
#define JUDGE_H

#include <vector>
#include <memory>
#include "player.h"
#include "board.h"
#include "history.h"
#include "common.h"

namespace Model
{

class Judge
{
    Board* board;
    History* history;
public:
    Judge(Board* theBoard, History* theHistory);
//    Player getNextPlayer() const { return nextPlayer; }
    

};

}

#endif // JUDGE_H