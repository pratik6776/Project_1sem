
#include "Word_guess.h"
#include <stdio.h>

int main() {
    welcome(); // Call the welcome function
    struct gamestate game = initialize(); // Initialize the game state

    printf("Guessed word: %s\n", game.guessed);
    printf("Tries left: %d\n", game.tries);
    printf("Game over: %d\n", game.gameover);
    char *word = selectWord(); 
    printf("The selected word is: %s\n", word);  // Print the word
    return 0;

    
}
