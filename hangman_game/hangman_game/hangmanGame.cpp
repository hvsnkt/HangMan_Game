#include "HangmanGame.h"
#include "randomword.h"

const char* theme;

HangmanGame::HangmanGame() {
    srand(time(0));
    secretWord = randomWord(getWordTheme());
    currentWord = string(secretWord.length(), '_');
    attemptsLeft = MAX;
}

void HangmanGame::play(const char* theme) {
    cout << "Добро пожаловать в игру!" << endl;
    cout << "Категория: " << theme << endl;
    cout << "У вас осталось " << attemptsLeft << " попыток угадать букву." << endl;

    while (attemptsLeft > 0) {
        statistics();
        unsigned char guess;
        cout << "Предположите букву: ";
        cin >> guess;

        if (isalpha(guess)) {
            guess = tolower(guess);
            if (alr_guessed(guess)) {
                cout << "Вы уже называли эту букву." << endl;
            }
            else {
                bool corr_guess = upd_word(guess);
                if (corr_guess) {
                    cout << "Отлично!" << endl;
                    if (currentWord == secretWord) {
                        statistics();
                        cout << "Поздравляем! Вы угадали слово: " << secretWord << endl;
                        return;
                    }
                }
                else {
                    cout << "Неправильно." << endl;
                    attemptsLeft--;
                }
            }
        }
        else {
            cout << "Пожалуйста, введите букву." << endl;
        }
    }

    if (attemptsLeft == 0) {
        statistics();
        cout << "У вас закончились попытки. Загаданное слово было: " << secretWord << endl;
    }
}

bool HangmanGame::alr_guessed(char letter) {
    return find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end();
}

bool HangmanGame::upd_word(char letter) {
    bool corr_guess = false;
    for (int i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == letter) {
            currentWord[i] = letter;
            corr_guess = true;
        }
    }
    guessedLetters.push_back(letter);
    return corr_guess;
}

void HangmanGame::statistics() {
    cout << "Слово: " << currentWord << endl;
    cout << "Осталось попыток: " << attemptsLeft << endl;
    cout << "Предположенные буквы: ";
    for (char letter : guessedLetters) {
        cout << letter << " ";
    }
    cout << endl;
}



string HangmanGame::getWordTheme() {
    string choose;
    cout << "Выберите тему: \n1 - Фрукты\t2 - Страны\t3 - Виды спорта\t4 - Кулинарные блюда\t5 - Цветы\n";
    cin >> choose;
    if (choose >= "1" && choose <= "5")
        return choose;
    else {
        exit();
    }
}
int HangmanGame::exit() {
    cout << "Неверный ввод";
    return 0;
}