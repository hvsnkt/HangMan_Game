#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#define MAX 6

using namespace std;

class HangmanGame {
public:
    HangmanGame();
    void play(const char* theme);
    int exit();

private:
    string secretWord;
    string currentWord;
    int attemptsLeft;
    vector<char> guessedLetters;

    bool alr_guessed(char letter);
    bool upd_word(char letter);
    void statistics();
    string getWordTheme(); 
};

