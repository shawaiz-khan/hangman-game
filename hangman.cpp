#include "WordProvider.h"
#include "Game.h"
#include <iostream>

using namespace std;

int main() {
    WordProvider provider("words.txt");
    string word = provider.getRandomWord();

    if (word.empty()) {
        cout << "No words available to play." << endl;
        return 1;
    }

    Game game(word);
    game.play();

    return 0;
}

