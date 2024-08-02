#include "Game.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

Game::Game(const string& word) {
    this->word = word;
    this->attemptsLeft = 6;
    this->incorrectGuessCount = 0;
    this->guessedWord = string(word.length(), '_');
    memset(this->incorrectGuesses, 0, sizeof(this->incorrectGuesses));
}

void Game::play() {
    displayLogo();
    char guess;
    while (attemptsLeft > 0 && !isWordGuessed()) {
        displayStatus();
        cout << "Enter your guess: ";
        cin >> guess;
        processGuess(guess);
    }

    if (isWordGuessed()) {
        cout << "Congratulations! You've guessed the word: " << word << endl;
    } else {
        cout << "Sorry, you've run out of attempts. The word was: " << word << endl;
    }
}

void Game::displayStatus() {
    displayHangman();
    cout << "Word: " << guessedWord << endl;
    cout << "Incorrect guesses: ";
    for (int i = 0; i < incorrectGuessCount; ++i) {
        cout << incorrectGuesses[i] << ' ';
    }
    cout << endl;
    cout << "Attempts left: " << attemptsLeft << endl;
}

bool Game::isWordGuessed() {
    return word == guessedWord;
}

void Game::processGuess(char guess) {
    bool correct = false;
    for (size_t i = 0; i < word.length(); ++i) {
        if (word[i] == guess) {
            guessedWord[i] = guess;
            correct = true;
        }
    }
    if (!correct) {
        incorrectGuesses[incorrectGuessCount++] = guess;
        --attemptsLeft;
    }
}

void Game::displayLogo() {
    const int LINE_WIDTH = 80;
    const string lines[7] = {
        "HH    HH     AA     NN    NN     GGG    MM          MM     AA     NN    NN",
        "HH    HH   AA  AA   NNN   NN   GG   GG  MMM        MMM   AA  AA   NNN   NN",
        "HH    HH  AA    AA  NNNN  NN  GG        MMMM      MMMM  AA    AA  NNNN  NN",
        "HHHHHHHH  AAAAAAAA  NN NN NN  GG        MM MM    MM MM  AAAAAAAA  NN NN NN",
        "HH    HH  AA    AA  NN  NNNN  GG   GGG  MM  MM  MM  MM  AA    AA  NN  NNNN",
        "HH    HH  AA    AA  NN   NNN   GG   GG  MM   MMMM   MM  AA    AA  NN   NNN",
        "HH    HH  AA    AA  NN    NN     GGG    MM    MM    MM  AA    AA  NN    NN"
    };

    cout << string(LINE_WIDTH, '-') << endl;
    cout << string(LINE_WIDTH, '-') << endl;

    for (int i = 0; i < 7; ++i) {
        cout << setw((LINE_WIDTH + lines[i].length()) / 2) << right << lines[i] << endl;
    }

    cout << string(LINE_WIDTH, '-') << endl;
    cout << string(LINE_WIDTH, '-') << endl;
}

void Game::displayHangman() {
    const char* stages[] = {
        "  +---+\n      |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n  |   |\n      |\n     ===",
        "  +---+\n  O   |\n /|   |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n /    |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n / \\  |\n     ==="
    };
    cout << endl << stages[7 - attemptsLeft] << endl;
}

