#ifndef GAME_H
#define GAME_H

/* Header files */
#include "rules.h"
#include "sleep.h"
#include "gameSavesLL.h"

/* Library used */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Create CONSTANTS declaration */
#define EMPTY_SYMBOL ' '
#define PLAYER_SYMBOL 'P'
#define FOOD_SYMBOL '@'
#define SNAKE_SYMBOL '~'
#define DELAY_TIME 0.1 /* Delay in seconds */
#define MIN_SIZE 5 /* Min size of map is 5x5 */

/* Functions FROM game.c */
void initialiseGameFromFile(const char *filename, int *row, int *col, int *playerRow, int *playerCol, int *snakeRow, int *snakeCol, int *foodRow, int *foodCol, char ***map);
void updateGameState(int *playerRow, int *playerCol, int *snakeRow, int *snakeCol, int row, int col, int *foodRow, int *foodCol, char **map);
void displayGameState(int row, int col, int playerRow, int playerCol, int snakeRow, int snakeCol, int foodRow, int foodCol);
int isGameOver(int playerRow, int playerCol, int snakeRow, int snakeCol);
int isGameWon(int playerRow, int playerCol, int foodRow, int foodCol);
void endGame();
void playGame(int row, int col, int playerRow, int playerCol, int snakeRow, int snakeCol, int foodRow, int foodCol, char **map);

#endif /* GAME_H */
