#include <iostream>

#include "state.hpp"
#include "utils.hpp"

using namespace std;
using namespace hangman;

const char* hangmen[] = {
    R"(
        |-----
             |
             |
             |
    )",
    R"(
        |-----
        O    |
             |
             |
    )",
    R"(
        |-----
        O    |
        |    |
             |
    )",
    R"(
        |-----
        O    |
        |\   |
             |
    )",
    R"(
        |-----
        O    |
       /|\   |
             |
    )",
    R"(
        |-----
        O    |
       /|\   |
         \   |
    )",

    R"(
        |-----
        O    |
       /|\   |
       / \   |
    )"
};

void printHangman(State const& s)
{
    auto incorrect_guesses_cnt = s.getIncorrectGuesses().size();
    cout << hangmen[incorrect_guesses_cnt] << endl;
}

int main(int argc, char** argv)
{
    cout << "Hangman" << endl;
    cout << hangmen[0] << endl;
    cout << "Secret word: ";
    string password = getPassword();
    cout << endl;
    State s(password);
    auto max_guesses = size(hangmen);
    cout << "Word: " << s.getGuessedWord('?') << endl;
    while (!s.guessedWord()) {
        char guess;
        cout << "Guess: ";
        cin >> guess;
        auto result = s.guess(guess);
        while (result == GuessResult::DUPLICATE) {
            cout << "Duplicate. Try again." << endl;
            cout << "Guess: ";
            cin >> guess;
            result = s.guess(guess);
        }
        if (result == GuessResult::CORRECT) {
            cout << "Correct guess!" << endl;
            cout << "Word: " << s.getGuessedWord('?') << endl;
        } else {
            cout << "Incorrect guess..." << endl;
            cout << "Hangman gained a limb..." << endl;
            printHangman(s);
        }
        if (s.getIncorrectGuesses().size() == max_guesses - 1)
            break;
    }
    if (s.guessedWord()) {
        cout << "You win!" << endl;

        return 0;
    } else {
        cout << "You lost! The word was " << password << "." << endl;
        return 1;
    }
}