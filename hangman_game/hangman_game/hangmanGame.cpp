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
    cout << "����� ���������� � ����!" << endl;
    cout << "���������: " << theme << endl;
    cout << "� ��� �������� " << attemptsLeft << " ������� ������� �����." << endl;

    while (attemptsLeft > 0) {
        statistics();
        unsigned char guess;
        cout << "������������ �����: ";
        cin >> guess;

        if (isalpha(guess)) {
            guess = tolower(guess);
            if (alr_guessed(guess)) {
                cout << "�� ��� �������� ��� �����." << endl;
            }
            else {
                bool corr_guess = upd_word(guess);
                if (corr_guess) {
                    cout << "�������!" << endl;
                    if (currentWord == secretWord) {
                        statistics();
                        cout << "�����������! �� ������� �����: " << secretWord << endl;
                        return;
                    }
                }
                else {
                    cout << "�����������." << endl;
                    attemptsLeft--;
                }
            }
        }
        else {
            cout << "����������, ������� �����." << endl;
        }
    }

    if (attemptsLeft == 0) {
        statistics();
        cout << "� ��� ����������� �������. ���������� ����� ����: " << secretWord << endl;
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
    cout << "�����: " << currentWord << endl;
    cout << "�������� �������: " << attemptsLeft << endl;
    cout << "�������������� �����: ";
    for (char letter : guessedLetters) {
        cout << letter << " ";
    }
    cout << endl;
}



string HangmanGame::getWordTheme() {
    string choose;
    cout << "�������� ����: \n1 - ������\t2 - ������\t3 - ���� ������\t4 - ���������� �����\t5 - �����\n";
    cin >> choose;
    if (choose >= "1" && choose <= "5")
        return choose;
    else {
        exit();
    }
}
int HangmanGame::exit() {
    cout << "�������� ����";
    return 0;
}