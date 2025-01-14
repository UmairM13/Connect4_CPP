#include <iostream>
#include <thread>
#include <future>
#include <atomic>
#include <chrono>
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
    bool useAI;
    bool timed;

public:
    Game(bool aiMode, bool timedMode)
        : player1('R'), player2('B'), aiPlayer('B'), currentPlayer(&player1), useAI(aiMode), timed(timedMode) {}

    void switchPlayer()
    {
        if (useAI)
        {
            currentPlayer = (currentPlayer == &player1) ? static_cast<Player *>(&aiPlayer) : &player1;
        }
        else
        {
            currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
        }
    }

    void play()
    {
        if (timed)
        {
            timedPlay();
        }
        else
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
    }

    void timedPlay()
    {
        while (true)
        {
            board.displayBoard();
            int move = (currentPlayer == &player1) ? getTimedMove() : currentPlayer->getMove();

            if (move == -1)
            {
                std::cout << "Time's up! Player " << currentPlayer->getPiece() << " loses!\n";
                break; // End the game immediately
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

    int getTimedMove()
    {
        // Look back here: https://stackoverflow.com/questions/28944972/how-to-use-a-timer-in-c-to-force-input-within-a-given-time
        // https://en.cppreference.com/w/cpp/thread
        // https://www.geeksforgeeks.org/std-promise-in-cpp/
        // Get move from player with a 5-second timeout
        // A promise like in JavaScript is used to communicate the move back to the main thread
        // std::promise<int> movePromise Object is instantiated so that it can be retrieved asynchronously
        // std::future<int> object is obtained from the promise, which will be used to retrieve the value of the move
        std::atomic<bool> inputReceived(false);
        int move = -1;

        // Start a new thread to get input from the player
        // runs the capture function in a seperate thread
        std::thread inputThread([&]()
                                {
                                std::cout << "Enter a column (1-7) or 0 to exit (You have 5 seconds): ";
                                std::cin >> move;
                                inputReceived = true; });

        // Wait for 5 seconds for input
        for (int i = 0; i < 50; ++i)
        {
            if (inputReceived)
            {
                inputThread.join(); // Input received, wait for the thread to finish
                return move - 1;    // Adjust move to zero-based indexing
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Small sleep to check periodically
        }

        inputThread.detach(); // Timeout, let the thread exit on its own
        return -1;            // Timeout results in an immediate loss
    }
};
