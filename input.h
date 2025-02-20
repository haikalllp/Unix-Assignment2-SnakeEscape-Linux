#ifndef INPUT_H
#define INPUT_H

/* Header Files */
#include "game.h"
#include "gameSavesLL.h"

/* libraries Used */
#include <stdio.h>
#include <termios.h>

/* Functions FROM input.c */
void handlePlayerMovement(int *playerRow, int *playerCol, int *snakeRow, int *snakeCol, int row, int col, char userInput);
char getUserInput();
void disableBuffer();
void enableBuffer();

#endif /* INPUT_H */
