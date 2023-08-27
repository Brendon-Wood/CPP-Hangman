#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>

std::string chooseSecretWord(const std::vector<std::string>& words);
bool loadWordsFromFile(const std::string& filename, std::vector<std::string>& words);

bool alreadyGuessed(const std::string& guessedWord, char guess);
bool checkGuess(const std::string& secretWord, std::string& guessedWord, char guess);

#endif
