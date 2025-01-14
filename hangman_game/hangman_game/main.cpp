#include <windows.h>
#include <iostream>
#include "randomWord.h"
int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    cout << randomWord();
}