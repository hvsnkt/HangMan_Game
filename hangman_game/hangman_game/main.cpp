#include <windows.h>
#include "HangmanGame.h"
extern const char* theme;
int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    HangmanGame game;
    game.play(theme);
    return 0;
}