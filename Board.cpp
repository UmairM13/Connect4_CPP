#include <iostream>
#include <vector>

class Board
{
    // defines a 2D vector of characters to represent the game board
    // provides methods to display the board, check if a move is valid, drop a piece into a column, check for a win, and check if the board is full
private:
    std::vector<std::vector<char>> board;

public:
    // constructor initializes the board with empty spaces
    // displayBoard method prints the current state of the board to the console

    Board()
    {
        board = std::vector<std::vector<char>>(6, std::vector<char>(7, '.')); // 6 rows, 7 columns
    }

    void displayBoard()
    {
        for (int row = 0; row < 6; ++row)
        {
            for (int col = 0; col < 7; ++col)
            {
                std::cout << board[row][col] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "1 2 3 4 5 6 7" << std::endl;
    }

    bool isValidMove(int column)
    {
        return board[0][column] == '.';
    }

    void dropPiece(int column, char player)
    {
        for (int row = 5; row >= 0; --row)
        {
            if (board[row][column] == '.')
            {
                board[row][column] = player;
                break;
            }
        }
    }

    bool checkWin(char player)
    {
        // Horizontal check
        for (int row = 0; row < 6; ++row)
        {
            for (int col = 0; col < 4; ++col)
            {
                if (board[row][col] == player && board[row][col + 1] == player && board[row][col + 2] == player && board[row][col + 3] == player)
                    return true;
            }
        }

        // Vertical check
        for (int col = 0; col < 7; ++col)
        {
            for (int row = 0; row < 3; ++row)
            {
                if (board[row][col] == player && board[row + 1][col] == player && board[row + 2][col] == player && board[row + 3][col] == player)
                    return true;
            }
        }

        // Diagonal (bottom-left to top-right) check
        for (int row = 3; row < 6; ++row)
        {
            for (int col = 0; col < 4; ++col)
            {
                if (board[row][col] == player && board[row - 1][col + 1] == player && board[row - 2][col + 2] == player && board[row - 3][col + 3] == player)
                    return true;
            }
        }

        // Diagonal (top-left to bottom-right) check
        for (int row = 0; row < 3; ++row)
        {
            for (int col = 0; col < 4; ++col)
            {
                if (board[row][col] == player && board[row + 1][col + 1] == player && board[row + 2][col + 2] == player && board[row + 3][col + 3] == player)
                    return true;
            }
        }

        return false;
    }

    bool isFull()
    {
        for (int col = 0; col < 7; ++col)
        {
            if (board[0][col] == '.')
                return false;
        }
        return true;
    }
};
