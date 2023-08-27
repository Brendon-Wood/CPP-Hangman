#include "drawing.h"
#include <iostream>

void drawHangman(int incorrectGuesses) {
    std::cout << "Incorrect guesses: " << incorrectGuesses << std::endl;

    // Draw the hangman based on the number of incorrect guesses
    switch (incorrectGuesses) {
        case 1:
            std::cout << "  ____" << std::endl;
            std::cout << " |    |" << std::endl;
            break;
        case 2:
            std::cout << "  ____" << std::endl;
            std::cout << " |    |" << std::endl;
            std::cout << " |    O" << std::endl;
            break;
        case 3:
            std::cout << "  ____" << std::endl;
            std::cout << " |    |" << std::endl;
            std::cout << " |    O" << std::endl;
            std::cout << " |    |" << std::endl;
            break;
        case 4:
            std::cout << "  ____" << std::endl;
            std::cout << " |    |" << std::endl;
            std::cout << " |    O" << std::endl;
            std::cout << " |   /|" << std::endl;
            break;
        case 5:
            std::cout << "  ____" << std::endl;
            std::cout << " |    |" << std::endl;
            std::cout << " |    O" << std::endl;
            std::cout << " |   /|\\" << std::endl;
            break;
        case 6:
            std::cout << "  ____" << std::endl;
            std::cout << " |    |" << std::endl;
            std::cout << " |    O" << std::endl;
            std::cout << " |   /|\\" << std::endl;
            std::cout << " |   / \\" << std::endl;
            std::cout << "Game Over! You've been hanged." << std::endl;
            break;
    }
}
