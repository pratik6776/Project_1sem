#include "Word_guess.h"
#include <stdio.h>
#include <string.h>

int main() {
    // Collect player info
    struct player_record player;
    printf("Enter your name: ");
    fgets(player.name, NAME_LENGTH, stdin);
    player.name[strcspn(player.name, "\n")] = '\0'; // Remove newline

    printf("Enter your age: ");
    scanf("%d", &player.age);
    getchar(); // Clear newline from input buffer

    // Start the game
    welcome();
    struct gamestate game = initialize();

    printf("Guessed word: %s\n", game.guessed);
    printf("Tries left: %d\n", game.tries);
    printf("Game over: %d\n", game.gameover);
    char *word = selectWord();
    printf("The game is ready!\n");

    while (game.tries > 0) {
        printf("\nGuessed word so far: ");
        
        for (int i = 0; word[i] != '\0'; i++) {
            if (strchr(game.guessed, word[i])) {
                printf("%c", word[i]);
            } else {
                printf("_ ");
            }
        }

        printf("\nTries left: %d\n", game.tries);

        int correct = getPlayerGuess(word, &game);

        int allGuessed = 1;
        for (int i = 0; word[i] != '\0'; i++) {
            if (!strchr(game.guessed, word[i])) {
                allGuessed = 0;
                break;
            }
        }

        if (allGuessed) {
            printf("Congratulations! You guessed the word: %s\n", word);
            strcpy(player.word_guessed, word); // Store the guessed word
            player.score = game.tries;         // Score = remaining tries
            save_player_record(&player);       // Save the record
            break;
        }

        if (game.tries == 0) {
            printf("Game Over! You've run out of tries. The word was: %s\n", word);
            strcpy(player.word_guessed, word); // Store the word even if lost
            player.score = 0;                  // Score = 0 if lost
            save_player_record(&player);       // Save the record
            break;
        }
        
    }
    return 0;
}
