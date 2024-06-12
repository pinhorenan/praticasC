#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <cctype>
using namespace std;

int main() {

    const string secret_word = "MYSTERY";
    string placeholder(secret_word.length(), '_');

    int lives = 10;
    char guess;
    
    bool game_over = false;

    cout << "*************************************" << endl;
    cout << "* Welcome to my word guessing game! *" << endl;
    cout << "*************************************" << endl;
    cout << "You have to guess the secret word!" << endl;
    cout << "Each time you make a wrong guess you'll lose a life. You start with 10 lives." << endl;
    cout << "Good luck!" << endl;

    while(!game_over) {
        int times_guess_appears = 0;

        cout << "The secret word is: " << placeholder << endl;
        cout << "You have " << lives << " lives remaining." << endl;
        cout << "Enter your guess: ";

        cin >> guess;

        while (!isalpha(guess)) {
            cout << "Invalid input! Please enter a letter." << endl;
            cin.ignore(10000, '\n');
            cout << "Enter your guess: ";
            cin >> guess;
        }

        guess = toupper(guess);

        for (int i = 0; i < secret_word.size(); i++) {
            if (toupper(secret_word[i]) == guess) {
                placeholder[i] = secret_word[i];
                times_guess_appears++;
            }
        }

        if(times_guess_appears > 0) {
            cout << "Congratulations! The letter " << guess << " appears " << times_guess_appears << " time(s) in the secret word." << endl;
        } else {
            cout << "Sorry! The letter " << guess << " is not in the secret word." << endl;
            lives--;
        }

        if (lives == 0) {
            cout << "Game over! You have reached the maximum number of mistakes." << endl;
            game_over = true;
        }

        if (secret_word == placeholder) {
            cout << "Congratulations! You guessed the secret word!" << endl;
            game_over = true;
        }
    }

    return 0;
}