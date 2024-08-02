#include "WordProvider.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

WordProvider::WordProvider(const string& filename) : wordCount(0) {
    ifstream file(filename.c_str());
    string word;
    while (file >> word && wordCount < 100) {
        words[wordCount++] = word;
    }
    srand(static_cast<unsigned int>(time(NULL)));
}

string WordProvider::getRandomWord() {
    if (wordCount == 0) return "";
    int index = rand() % wordCount;
    return words[index];
}

