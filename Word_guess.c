#include "Word_guess.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>


void welcome() {
    printf("Welcome to the Word Guessing Game!\n");
    printf("Instructions:\n");
    printf("1. A random word will be selected for you to guess.\n");
    printf("2. You have a limited number of tries to guess the word.\n");
    printf("3. Guess one letter at a time.\n");
    printf("4. You win when you guess all the letters correctly!\n");
    printf("Good luck!\n\n");
}

struct gamestate initialize() {
    struct gamestate game; // structure variable
    strcpy(game.guessed, "");
    game.tries = 6;
    game.gameover = 0;
    return game;
}

char* selectWord() {
    static char word[MIN];  // Holds the selected word

    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char wordList[MAX][MIN];  // Array to store words from file
    int count = 0;  // Word counter

    // Read words from file
    while (fgets(wordList[count], MIN, file) != NULL) {
        wordList[count][strcspn(wordList[count], "\n")] = '\0';  // Remove newline
        count++;
    }
    fclose(file);

    // Pick a random word
    srand(time(0));
    int randomIndex = rand() % count;

    strcpy(word, wordList[randomIndex]);  // Copy the selected word

    return word;  // Return pointer to selected word
}
