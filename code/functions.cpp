#include "functions.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

std::string chooseSecretWord(const std::vector<std::string>& words) {
    // Seed the random number generator
    std::srand(std::time(0));

    // Choose a random word from the list
    int randomIndex = std::rand() % words.size();
    return words[randomIndex];
}

bool loadWordsFromFile(const std::string& filename, std::vector<std::string>& words) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false; // Failed to open file
    }

    std::string word;
    while (std::getline(file, word)) {
        words.push_back(word);
    }

    file.close();
    return true; // Successfully loaded words from file
}

bool alreadyGuessed(const std::string& guessedWord, char guess) {
    return guessedWord.find(guess) != std::string::npos;
}

bool checkGuess(const std::string& secretWord, std::string& guessedWord, char guess) {
    bool correctGuess = false;

    for (size_t i = 0; i < secretWord.length(); ++i) {
        if (secretWord[i] == guess) {
            guessedWord[i] = guess;
            correctGuess = true;
        }
    }

    return correctGuess;
}

