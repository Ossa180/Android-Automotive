#include <iostream>
#include <cstdlib>   // For std::rand(), std::srand()
#include <ctime>     // For std::time>
#include <stdexcept> // For std::out_of_range

class Battleship
{
private:
    bool board[5][5];
    static int guesses;
    int max_guesses;
    int x_location;
    int y_location;

public:
    Battleship(int max_guesses) : max_guesses{max_guesses}
    {
        // Initialize the board to false
        for (auto &row : board)
        {
            for (bool &element : row)
                element = false;
        }
        // Initialize the random seed
        std::srand(std::time(nullptr));
        // Randomly place the ship
        x_location = std::rand() % 5;
        y_location = std::rand() % 5;

        // Initialize the number of guesses
        guesses = 0;
    }

    bool guess(int x, int y)
    {
        if (x < 0 || x >= 5 || y < 0 || y >= 5)
        {
            throw std::out_of_range("Coordinates are out of bounds.");
        }

        if (x == x_location && y == y_location)
        {
            std::cout << "bravoo correct guess\n";
            return true;
        }
        return false;
    }

    void wrong_guess()
    {
        std::cout << "Wrong guess!\n";
        guesses++;
        std::cout << "You have " << max_guesses - guesses << " guesses left.\n";
    }

    bool game_over() const
    {
        return guesses >= max_guesses;
    }

    int get_guesses() const
    {
        return guesses;
    }
};

int Battleship::guesses = 0;

int main()
{
    try
    {
        Battleship game(5);
        std::cout << "Welcome \n";
        while (!game.game_over())
        {
            int x, y;
            std::cout << "Enter the x and y coordinates (0-4): ";
            std::cin >> x >> y;
            try
            {
                if (game.guess(x, y))
                    break;
                else
                {
                    game.wrong_guess();
                }
            }
            catch (const std::out_of_range &e)
            {
                std::cerr << "Error: " << e.what() << "\n";
            }
        }

        if (game.game_over() && !game.guess(0, 0)) // if game over and ship not found
        {
            std::cout << "Game Over. You've used all your guesses.\n";
        }

        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return 1;
    }
}
