#include "Word_guess.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void welcome() {
    printf("======================================\n");
    printf("          WELCOME TO                 \n");
    printf("      WORD GUESSING GAME!            \n");
    printf("======================================\n\n");
    printf("       Instructions:                 \n");
    printf("       >> Guess one letter at a time.\n");
    printf("       >> You have %d tries to win!  \n", MAX_TRIES);
    printf("======================================\n");
    printf("    Are you ready to guess a word?   \n");
    printf("======================================\n");
    printf("          [Y/N] ");
    char response;
    scanf(" %c", &response);
    if (response == 'N' || response == 'n') {
        printf("======================================\n");
        printf("    Okay, come back when you're ready!\n");
        printf("======================================\n");
        exit(0);
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("        GAME STARTS NOW              \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}

struct gamestate initialize() {
    printf("======================================\n");
    printf("      Initializing Game...           \n");
    printf("======================================\n");

    struct gamestate game;
    strcpy(game.guessed, ""); // Initialize guessed letters as empty
    game.tries = MAX_TRIES;   // Set tries to maximum
    game.gameover = 0;        // Game not over yet
    game.word[0] = '\0';      // Empty word initially
    printf("~~~~~ Game Initialized Successfully ~~~~~\n\n");
    return game;
}

char* selectWord() {
    printf("======================================\n");
    printf("      Selecting a Word...            \n");
    printf("======================================\n");

    static char word[MIN];
    char wordList[MAX][MIN];
    int count = 0;

    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("######################################\n");
        printf("    Error: Cannot open words.txt file \n");
        printf("######################################\n");
        exit(1);
    }

    while (fgets(wordList[count], MIN, file) != NULL) {
        wordList[count][strcspn(wordList[count], "\n")] = '\0'; // Remove newline
        count++;
        if (count >= MAX) break;
    }
    fclose(file);

    if (count == 0) {
        printf("######################################\n");
        printf("    Error: No words found in file    \n");
        printf("######################################\n");
        exit(1);
    }

    srand(time(NULL));
    int randomIndex = rand() % count;
    strcpy(word, wordList[randomIndex]);

    printf("~~~~~ Word Selected Successfully ~~~~~\n\n");
    return word;
}

int getPlayerGuess(char word[], struct gamestate* game) {
    char guess;
    int correct = 0;

    printf("=================\n");
    printf("    Enter a letter: ");
    scanf(" %c", &guess);

    if (strchr(game->guessed, guess)) {
        printf("-----------------\n");
        printf("    You've already guessed that letter!\n");
        printf("-----------------\n");
        return correct;
    }

    strncat(game->guessed, &guess, 1);

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == guess) {
            correct = 1;
            break;
        }
    }

    if (correct) {
        printf("-----------------\n");
        printf("    Correct guess!\n");
        printf("-----------------\n");
    } else {
        printf("-----------------\n");
        printf("    Incorrect guess.\n");
        printf("-----------------\n");
        game->tries--;
    }

    return correct;
}

void save_player_record(struct player_record* record) {
    printf("======================================\n");
    printf("      Saving Player Record...        \n");
    printf("======================================\n");

    FILE *file = fopen("player_records.txt", "a"); // "a" for append mode
    if (file == NULL) {
        printf("######################################\n");
        printf("    Error: Cannot open player_records.txt for writing\n");
        printf("######################################\n");
        return;
    }

    // Write record in a formatted way
    fprintf(file, "Name: %s, Age: %d, Word: %s, Score: %d\n",
            record->name, record->age, record->word_guessed, record->score);

    fclose(file);
    printf("~~~~~ Player record saved to player_records.txt ~~~~~\n");
    printf("======================================\n\n");
}
