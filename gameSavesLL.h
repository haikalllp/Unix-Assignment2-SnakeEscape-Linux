/* gameSavesLL.h */

#ifndef GAMESAVESLL_H
#define GAMESAVESLL_H

#include "game.h"

/* Struct to store the game state */
typedef struct GameState {
    int playerRow;
    int playerCol;
    int snakeRow;
    int snakeCol;
    struct GameState* next;
} GameState;

/* Functions FROM gameSavesLL.c */
void saveGameState(GameState** head, int playerRow, int playerCol, int snakeRow, int snakeCol);
void retrieveGameState(GameState** head, int* playerRow, int* playerCol, int* snakeRow, int* snakeCol);
int isEmpty(GameState* head);
void freeList(GameState* head);

#endif /* GAMESAVESLL_H */
