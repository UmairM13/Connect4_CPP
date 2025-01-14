#include <iostream>
#include "Game.cpp"

int main()
{
    int choice;
    std::cout << "Connect 4!\n";
    std::cout << "1. Play against another player\n";
    std::cout << "2. Play against an AI\n";
    std::cout << "Please select an option (0 to exit): ";
    std::cin >> choice;

    if (choice == 0)
    {
        std::cout << "Game exited. Thanks for playing!\n";
        return 0;
    }
    else if (choice == 1)
    {
        Game game(false);
        game.play();
    }
    else if (choice == 2)
    {
        Game game(true);
        game.play();
    }
    else
    {
        std::cout << "Invalid option. Exiting.\n";
    }
    return 0;
}
