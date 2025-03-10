#ifndef WORD_GUESS_H
#define WORD_GUESS_H

#define MAX 30     // Maximum number of words in the word list
#define MIN 11     // Maximum length of each word
#define MAX_TRIES 6 // Number of tries
#define NAME_LENGTH 50

struct gamestate {
    char guessed[100];  // To store letters guessed so far
    int tries;          // Number of tries left
    int gameover;       // Flag to indicate if game is over
    char word[MIN];     // To store the selected word
};
struct player_record {
    char name[NAME_LENGTH];  // Player's name
    int age;                 // Player's age
    char word_guessed[MIN];  // Word the player guessed (matches word length)
    int score;               // Player's score
};
void welcome();
struct gamestate initialize();
char* selectWord();
int getPlayerGuess(char word[], struct gamestate* game);
void save_player_record(struct player_record* record);
#endif
