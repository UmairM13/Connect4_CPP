#ifndef AIPLAYER_H
#define AIPLAYER_H

#include <cstdlib>
#include <ctime>
#include "Player.h"

class AIPlayer : public Player
{
public:
    AIPlayer(char p) : Player(p)
    {
        // Seed the random number generator
        std::srand(static_cast<unsigned>(std::time(0)));
    }

    int getMove() override
    {
        int move = std::rand() % 7;
        std::cout << "AI chooses column " << (move + 1) << std::endl;
        return move;
    }
};

#endif
