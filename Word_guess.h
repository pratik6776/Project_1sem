#ifndef WORD_GUESS_H
#define WORD_GUESS_H
#define MAX 30
#define MIN 11


// Structure definition
struct gamestate {

    char guessed[100];
    int tries;
    int gameover;
    char word[MAX][MIN];
};

// Function prototypes
void welcome();
struct gamestate initialize();
char* selectWord();
#endif
