#include <iostream>

class Player
{
private:
    char piece;

public:
    Player(char p) : piece(p) {}

    char getPiece() const
    {
        return piece;
    }

    int getMove()
    {
        int move;
        std::cout << "Enter a column (1-7) or 0 to exit:  ";
        std::cin >> move;
        return move - 1;
    }
};
