#include "functions.h"
#include "drawing.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

int main() {
    std::vector<std::string> words;
    if (loadWordsFromFile("words.txt", words)) {
        std::string secretWord = chooseSecretWord(words);
        std::string guessedWord(secretWord.length(), '_');
        int incorrectGuesses = 0;

        while (incorrectGuesses < MAX_INCORRECT_GUESSES) {
            std::cout << "Secret Word: " << guessedWord << std::endl;
            char guess;
            std::cout << "Enter a letter: ";
            std::cin >> guess;

            if (!isalpha(guess)) {
                std::cout << "Please enter a valid letter." << std::endl;
                continue;
            }

            if (alreadyGuessed(guessedWord, guess)) {
                std::cout << "You've already guessed that letter." << std::endl;
                continue;
            }

            if (checkGuess(secretWord, guessedWord, guess)) {
                std::cout << "Correct guess!" << std::endl;
            } else {
                std::cout << "Incorrect guess!" << std::endl;
                incorrectGuesses++;
                drawHangman(incorrectGuesses);
            }

            if (secretWord == guessedWord) {
                std::cout << "Congratulations! You've guessed the word: " << secretWord << std::endl;
                break;
            }
        }

        if (incorrectGuesses >= MAX_INCORRECT_GUESSES) {
            std::cout << "Sorry, you've run out of guesses. The word was: " << secretWord << std::endl;
        }
    } else {
        std::cerr << "Failed to load words from file." << std::endl;
    }

    return 0;
}
