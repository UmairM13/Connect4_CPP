#include <iostream>
#include "Board.cpp"
#include "Player.cpp"

class Game
{
private:
    Board board;
    Player player1;
    Player player2;
    Player *currentPlayer;

public:
    Game() : player1('R'), player2('B'), currentPlayer(&player1) {}

    void switchPlayer()
    {
        currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
    }

    void play()
    {
        while (true)
        {
            board.displayBoard();
            int move = currentPlayer->getMove();
            if (!board.isValidMove(move))
            {
                std::cout << "Invalid move! Try again.\n";
                continue;
            }
            board.dropPiece(move, currentPlayer->getPiece());

            if (board.checkWin(currentPlayer->getPiece()))
            {
                board.displayBoard();
                std::cout << "Player " << currentPlayer->getPiece() << " wins!\n";
                break;
            }

            if (board.isFull())
            {
                board.displayBoard();
                std::cout << "It's a tie!\n";
                break;
            }

            switchPlayer();
        }
    }
};
