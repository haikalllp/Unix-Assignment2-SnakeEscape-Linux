/* game.c */

/* Header files */
#include "game.h"
#include "input.h"
#include "sleep.h"
#include "randomGen.h"
#include "gameSavesLL.h"

/* Library Used */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Modified from Assignment 1 */
/* Original: initializeGame() from game.c*/
/* Function to initialize game state */
/* New Feature: read map from a .txt file using fileIO and then initialize the game based on info in the file */
void initialiseGameFromFile(const char *filename, int *row, int *col, int *playerRow, int *playerCol, int *snakeRow, int *snakeCol, int *foodRow, int *foodCol, char ***map) {
    FILE *file;
    int i, j, entity;

    /* Open the file */
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    /* Read map dimensions */
    if (fscanf(file, "%d %d", row, col) != 2) {
        printf("Error: Invalid file format for map dimensions.\n");
        fclose(file);
        exit(1);
    }

    /* Allocate memory for the map */
    *map = (char **)malloc(*row * sizeof(char *));
    if (*map == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(file);
        exit(1);
    }
    for (i = 0; i < *row; i++) {
        (*map)[i] = (char *)malloc(*col * sizeof(char));
        if ((*map)[i] == NULL) {
            printf("Error: Memory allocation failed.\n");
            fclose(file);
            exit(1);
        }
    }

    /* Read map data from file */
    for (i = 0; i < *row; i++) {
        for (j = 0; j < *col; j++) {
            if (fscanf(file, "%d", &entity) != 1) {
                printf("Error: Invalid file format for map data.\n");
                fclose(file);
                exit(1);
            }
            /* Store entity in the map */
            (*map)[i][j] = (char)entity;
            /* Initialise player, snake, and food positions */
            if (entity == 1) {
                *playerRow = i;
                *playerCol = j;
            } else if (entity == 2) {
                *snakeRow = i;
                *snakeCol = j;
            } else if (entity == 3) {
                *foodRow = i;
                *foodCol = j;
            }
        }
    }

    /* Close the file */
    fclose(file);
}



/* Modified from Assignment 1 */
/* Function to update the game state */
/* New feature added: now let the snake to warp around the map when collide with border */
void updateGameState(int *playerRow, int *playerCol, int *snakeRow, int *snakeCol, int row, int col, int *foodRow, int *foodCol, char **map) {
    int rowBound, colBound, boundarySize, newSnakeCol, newSnakeRow;
    boundarySize = 1; /* Size of the boundary around the snake */
    
    /* Update map with player position */
    map[*playerRow][*playerCol] = PLAYER_SYMBOL;

    /* Check if player enters the boundary around the snake */
    rowBound = abs(*playerRow - *snakeRow);
    colBound = abs(*playerCol - *snakeCol);
    if (rowBound <= boundarySize && colBound <= boundarySize) { /* if yes */
        /* Jump the snake to the player's position and eat the player */
        map[*snakeRow][*snakeCol] = EMPTY_SYMBOL;
        *snakeRow = *playerRow;
        *snakeCol = *playerCol;

        /* Update map with snake's new position */
        map[*snakeRow][*snakeCol] = SNAKE_SYMBOL;

        /* Remove the player symbol from the map */
        map[*playerRow][*playerCol] = EMPTY_SYMBOL;

        /* Ensure that game is over as snake ate player */
        isGameOver(*playerRow, *playerCol, *snakeRow, *snakeCol);
    } else { /* if not */

    /* Do Random Snake movement iteration */
    do {
        /* Generate random movement for the snake */
        newSnakeRow = *snakeRow + getRandomNumber(-1, 1);
        newSnakeCol = *snakeCol + getRandomNumber(-1, 1);

        /* Check if collide with border */
        /* Wrap snake position around the map borders if collide with border */
        if (newSnakeRow < 0) {
            newSnakeRow = row - 1; /* Wrap to bottom if collide with top border */
        } else if (newSnakeRow >= row) {
            newSnakeRow = 0; /* Wrap to top if collide with bottom border */
        }
        if (newSnakeCol < 0) {
            newSnakeCol = col - 1; /* Wrap to right if collide with left border */
        } else if (newSnakeCol >= col) {
            newSnakeCol = 0; /* Wrap to left if collide with right border */
        }

        /* Ensure that new location is not the same as food and not the same as the old snake position */
    } while ((newSnakeRow == *foodRow && newSnakeCol == *foodCol) || (newSnakeRow == *snakeRow && newSnakeCol == *snakeCol));

    /* Update map with new snake position */
    map[*snakeRow][*snakeCol] = EMPTY_SYMBOL; /* Clear the snake's current position */
    *snakeRow = newSnakeRow; /* Update snake's row */
    *snakeCol = newSnakeCol; /* Update snake's column */
    map[*snakeRow][*snakeCol] = SNAKE_SYMBOL; /* Update the snake's position on the map */
    }
    
}

/* Function to display the game state */
void displayGameState(int row, int col, int playerRow, int playerCol, int snakeRow, int snakeCol, int foodRow, int foodCol) {
    int i, j; /* Loop variables */

    /* Clear screen */
    system("clear");

    /*Show Size of Map*/
    printf("\nSize of Game Map: \nrow %d, column %d\n", row, col);

    /* Display border */
    for (j = 0; j < col + 2; j++) {
        printf("*"); /* create top border */
    }
    printf("\n");

    /* Display map */
    for (i = 0; i < row; i++) {
        printf("*"); /* create left border */
        for (j = 0; j < col; j++) {
            if (i == snakeRow && j == snakeCol) {
                printf("%c", SNAKE_SYMBOL);
            } else if (i == playerRow && j == playerCol) {
                if (snakeRow == playerRow && snakeCol == playerCol) {
                    printf("%c", SNAKE_SYMBOL); /* If player and snake are at the same position, display snake symbol = lost */
                } else {
                    printf("%c", PLAYER_SYMBOL);
                }
            } else if (i == foodRow && j == foodCol) {
                printf("%c", FOOD_SYMBOL);
            } else {
                printf("%c", EMPTY_SYMBOL);
            }
        }
        printf("*\n"); /* create right border */
    }

    /* Display border */
    for (j = 0; j < col + 2; j++) {
        printf("*"); /* create bottom border */
    }
    printf("\n");

    /* Display controls */
    printf("Press \"W\" to move up\n");
    printf("Press \"S\" to move down\n");
    printf("Press \"A\" to move left\n");
    printf("Press \"D\" to move right\n");
    printf("Press \"U\" to undo move\n");
    printf("\nPress \"Q\" to exit\n");
}

/* Function to check if the game is over */
int isGameOver(int playerRow, int playerCol, int snakeRow, int snakeCol) {
    return (playerRow == snakeRow && playerCol == snakeCol);
}

/* Function to check if the game is won */
int isGameWon(int playerRow, int playerCol, int foodRow, int foodCol) {
    return (playerRow == foodRow && playerCol == foodCol);
}

/* Function to end the game */
void endGame() {
    exit(0);
}

/* Modified from Assignment 1 */
/* Function to play the game */
/* New Feature: game now can undo, first get user input, check if it is undo or not. */
/* If undo 'u' game will call the function to undo game state. */
/* If not undo game will take input and bring to player movemend handler. */
/* Then process of game logic proceed as same, save current state of game, player input, update game state with snake movement, display state  */
void playGame(int row, int col, int playerRow, int playerCol, int snakeRow, int snakeCol, int foodRow, int foodCol, char **map) {
    /* Local Variables */
    GameState* currentState = NULL;
    char userInput;

    while (1) { /* Game logic will loops until game ends */
        /* Get user input */
        userInput = getUserInput();

        /* if user input is 'u' do undo feature */
        if (userInput == 'u' || userInput == 'U') {
            if (!isEmpty(currentState)) {
                /* Retrieve prev game state from linked list */
                retrieveGameState(&currentState, &playerRow, &playerCol, &snakeRow, &snakeCol);

                /* Display the game state */
                displayGameState(row, col, playerRow, playerCol, snakeRow, snakeCol, foodRow, foodCol);
                printf("\r\033[K");
                printf("Undid movement.\n");
            } else {
                printf("\r\033[K");
                printf("Cannot undo further.\n");
            }

        /* if user input is 'q' exit game */
        } else if (userInput == 'q' || userInput == 'Q') {
            printf("\r\033[K");
            printf("\nExited out of game.\n");
            endGame();

        /* if user input is none of those it will do normal input for movement and proceed with the game */
        } else {
            /* Save current game state to linked list */
            saveGameState(&currentState, playerRow, playerCol, snakeRow, snakeCol);

            /* Take user input to handle player movement */
            handlePlayerMovement(&playerRow, &playerCol, &snakeRow, &snakeCol, row, col, userInput);

            /* Update game state */
            updateGameState(&playerRow, &playerCol, &snakeRow, &snakeCol, row, col, &foodRow, &foodCol, map);

            /* Display game state */
            displayGameState(row, col, playerRow, playerCol, snakeRow, snakeCol, foodRow, foodCol);
        }

        /* Delay to slow down the game and ensure that it works and game doesnt skip */
        delay(DELAY_TIME); /* Delay_time is constant value FROM game.h */

        /* Check for game over or win condition */
        if (isGameOver(playerRow, playerCol, snakeRow, snakeCol)) {
            printf("\nThe snake ate you! Game over.\n");
            break; 
        } else if (isGameWon(playerRow, playerCol, foodRow, foodCol)) {
            printf("\nYou won!\n");
            break; 
        }
    }

    /* Free the linked list after game is finish */
    freeList(currentState);
    
}

