#ifndef WORDPROVIDER_H
#define WORDPROVIDER_H

#include <string>

using namespace std;

class WordProvider {
private:
    string words[100];
    int wordCount;
public:
    WordProvider(const string& filename);
    string getRandomWord();
};

#endif