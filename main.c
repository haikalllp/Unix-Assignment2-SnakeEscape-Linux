/* main.c */

/* Header files */
#include "game.h"
#include "rules.h"
#include "input.h"
#include "gameSavesLL.h"

/* Library used */
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>  

/* Modified from Assignment 1 */
/* Original: main.c*/
/* New Feature: accept command line argument of a txt file that contains map data */
/* New Feature: initialiseGameFromFile() is now used, as txt file is used to initialise map data */
int main(int argc, char *argv[]) {
    /* Map variables */
    int row, col;
    char **map = NULL;

    /* Entities */
    int playerRow, playerCol;
    int snakeRow, snakeCol;
    int foodRow, foodCol;

    /* Main's Variable */
    int i;

    /* LinkedList Stack for storing game states */
    GameState *currentState = NULL;
    GameState *temp;
    
    /* Seed the random number generator */
    srand(time(NULL));

    /* Check if correct arguments are provided */
    if (argc != 2) {
        printf("Usage: %s <map_filename.txt>\n", argv[0]);
        return 0;
    }

    /* Initialise game from file */
    initialiseGameFromFile(argv[1], &row, &col, &playerRow, &playerCol, &snakeRow, &snakeCol, &foodRow, &foodCol, &map);

    /* Save the INITIAL state of the game to linked list */
    saveGameState(&currentState, playerRow, playerCol, snakeRow, snakeCol);

    /* Display game rules first FROM rules.c */
    displayRules();

    /* Wait for user to press Enter before proceeding */
    while (getchar() != '\n');

    /* Display game state FROM game.c */
    displayGameState(row, col, playerRow, playerCol, snakeRow, snakeCol, foodRow, foodCol);

    /* Play the game FROM game.c (The game logic loops until game ends) */
    playGame(row, col, playerRow, playerCol, snakeRow, snakeCol, foodRow, foodCol, map);

    /* Free memory allocated for the map after game end */
    for (i = 0; i < row; i++) {
        free(map[i]);
    }
    free(map);

    /* Free the LinkedList stack */
    while (currentState) {
        temp = currentState;
        currentState = currentState->next;
        free(temp);
    }

    return 0;
}

