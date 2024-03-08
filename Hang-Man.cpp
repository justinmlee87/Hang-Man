#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to check if the guessed letter is in the word
bool isLetterInWord(char letter, const string& word, vector<bool>& guessedLetters) {
    bool found = false;
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == letter) {
            found = true;
            guessedLetters[i] = true;
        }
    }
    return found;
}

// Function to display the current state of the word with underscores for unrevealed letters
void displayWord(const string& word, const vector<bool>& guessedLetters) {
    for (int i = 0; i < word.length(); ++i) {
        if (guessedLetters[i]) {
            cout << word[i] << " ";
        }
        else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    // Set up a list of words
    vector<string> words = { "hangman", "programming", "computer", "language", "challenge" };

    // Seed the random number generator
    srand(time(0));

    // Select a random word from the list
    int randomIndex = rand() % words.size();
    string secretWord = words[randomIndex];

    // Initialize guessedLetters vector to track which letters have been guessed
    vector<bool> guessedLetters(secretWord.length(), false);

    // Set up the maximum number of incorrect guesses allowed
    const int maxIncorrectGuesses = 6;
    int incorrectGuesses = 0;

    cout << "Welcome to Hangman!" << endl;

    while (incorrectGuesses < maxIncorrectGuesses) {
        // Display current state of the word
        displayWord(secretWord, guessedLetters);

        // Get a letter guess from the player
        cout << "Enter a letter guess: ";
        char guess;
        cin >> guess;

        // Check if the letter is in the word
        if (isLetterInWord(guess, secretWord, guessedLetters)) {
            cout << "Good guess!" << endl;
        }
        else {
            cout << "Incorrect guess. Try again." << endl;
            ++incorrectGuesses;
        }

        // Check if the word has been fully guessed
        if (guessedLetters == vector<bool>(secretWord.length(), true)) {
            cout << "Congratulations! You guessed the word: " << secretWord << endl;
            break;
        }
    }

    // If the player runs out of guesses
    if (incorrectGuesses == maxIncorrectGuesses) {
        cout << "Sorry, you ran out of guesses. The correct word was: " << secretWord << endl;
    }

    return 0;
}