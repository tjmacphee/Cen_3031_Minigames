//
// Created by julia on 10/23/2022.
//
#include "Hangman.h"

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void returnArray(string arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

string easy() {
    // hint animals
    // maybe one letter already revealed
    string word[5] = {"bear", "hippo", "rabbit", "monkey", "horse"};

    // found random number generator
    // https://java2blog.com/random-number-between-1-and-10-cpp/
    srand(time(0));
    int rand_num = (rand() % 5) + 1;

    switch (rand_num) {
        case 1:
            return word[0];
            break;
        case 2:
            return word[1];
            break;
        case 3:
            return word[2];
            break;
        case 4:
            return word[3];
            break;
        case 5:
            return word[4];
            break;
    }
    return word[0];
}

string medium() {
    // hint but no free letter
    // Gamer Villains
    string word[5] = {"bowzer", "glados", "gannon", "ridley", "robotnik"};

    srand(time(0));
    int rand_num = (rand() % 5) + 1;

    switch (rand_num) {
        case 1:
            return word[0];
            break;
        case 2:
            return word[1];
            break;
        case 3:
            return word[2];
            break;
        case 4:
            return word[3];
            break;
        case 5:
            return word[4];
            break;
    }
    return word[0];
}

string hard() {
    // no hints and random words
    string word[5] = {"jazz", "abrupt", "match", "rythm", "buzzing"};

    srand(time(0));
    int rand_num = (rand() % 5) + 1;

    switch (rand_num) {
        case 1:
            return word[0];
            break;
        case 2:
            return word[1];
            break;
        case 3:
            return word[2];
            break;
        case 4:
            return word[3];
            break;
        case 5:
            return word[4];
            break;
    }
    return word[0];
}

char wordArray() {}

void game(string word) {
    int len = word.length();
    char wordArray[len];
    strcpy(wordArray, word.c_str());
    char userArray[len];

    for (int i = 0; i < len; i++) {
        userArray[i] = '_';
    }

    int userLife = 9; // user life count before stick figure
    char userChoice;
    for (int i = 0; i < len; i++) {
        cout << " _" << userArray[i] << "_ ";
    }

    while (userLife > 0) {
        cout << "number of lives: " << userLife << endl;
        cout << "letter choice: ";
        cin >> userChoice;
        cout << endl;
        for (int i = 0; i < word.length(); i++) {
            if (userChoice == wordArray[i]) {
                userArray[i] = userChoice;
                cout << " _" << userArray[i] << "_ ";

            } else {
                cout << " _"<<userArray[i]<<"_ ";
            }
        }
    }
}

void hangman() {
    int choice; // user difficulty choice
    string word;
    cout << "Welcome to Hangman! \nPlease select a Difficulty Level: \n[1] Easy "
            "\n[2] Medium \n[3] Hard\n\n";
    cin >> choice;

    switch (choice) {
        case 1: // easy
            word = easy();
            cout << "Hint: Animals\n" << word << "\n\n";

            game(word);
            break;

        case 2: // medium
            word = medium();
            cout << "Hint: Famous Game Villains\n" << word << "\n\n";
            game(word);
            break;

        case 3: // hard
            word = hard();
            cout << word << "\n\n";
            game(word);
            break;
    }
}