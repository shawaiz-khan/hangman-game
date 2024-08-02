#ifndef GAME_H
#define GAME_H

#include <string>

using namespace std;

class Game {
public:
    Game(const string& word);
    void play();

private:
    string word;
    string guessedWord;
    int attemptsLeft;
    char incorrectGuesses[26];
    int incorrectGuessCount;

    void displayStatus();
    bool isWordGuessed();
    void processGuess(char guess);
    void displayLogo();
    void displayHangman();
};

#endif