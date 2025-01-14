#include <iostream>
#include "Board.cpp"
#include "Player.h"
#include "AIPlayer.h"

class Game
{
private:
    Board board;
    Player player1;
    Player player2;
    AIPlayer aiPlayer;
    Player *currentPlayer;
    bool aiMode;

public:
    Game(bool useAI = false) : player1('R'), player2('B'), aiPlayer('B'), currentPlayer(&player1), aiMode(useAI) {}

    void switchPlayer()
    {
        if (aiMode)
        {
            currentPlayer = (currentPlayer == &player1) ? &aiPlayer : &player1;
        }
        else
        {
            currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
        }
    }

    void play()
    {
        while (true)
        {
            board.displayBoard();
            int move = currentPlayer->getMove();
            if (move == -1)
            {
                std::cout << "Game exited. Thanks for playing!\n";
                break;
            }
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
