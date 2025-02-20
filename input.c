/* input.c */

/* Header files */
#include "input.h"
#include "game.h"
#include "gameSavesLL.h"

/* library used */
#include <stdio.h>

/* Reference: Suplementary video */
/* Function to disable terminal input buffering */
void disableBuffer() {
    struct termios mode;
    tcgetattr(0, &mode);
    mode.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(0, TCSANOW, &mode);
}

/* Reference: Suplementary video */
/* Function to enable terminal input buffering */
void enableBuffer() {
    struct termios mode;
    tcgetattr(0, &mode);
    mode.c_lflag |= (ECHO | ICANON);
    tcsetattr(0, TCSANOW, &mode);
}

/* Funtion that handle user inputs for normal input and immediately get them */
char getUserInput() {
    char userInput;
    disableBuffer(); /* Disable input buffering */
    userInput = getchar(); /* Read a single character */
    enableBuffer(); /* Enable input buffering */
    return userInput;
}

/* Modified from Assignment 1 */
/* Function to handle player movement input */
/* New feature added: now let player to warp around the map when collided with border */
/* New feature added: now strictly only handle player movement */
void handlePlayerMovement(int *playerRow, int *playerCol, int *snakeRow, int *snakeCol, int row, int col, char userInput) {

    switch (userInput) {
        case 'w': case 'W': /* Move player up */
            *playerRow = (*playerRow - 1 + row) % row; /* allow player to warp from top border to bottom border */
            break;
        case 'a': case 'A': /* Move player left */
            *playerCol = (*playerCol - 1 + col) % col; /* allow player to warp from left border to right border */
            break;
        case 's': case 'S': /* Move player down */
            *playerRow = (*playerRow + 1) % row; /* allow player to warp from bottom border to top border */
            break;
        case 'd': case 'D': /* Move player right */
            *playerCol = (*playerCol + 1) % col; /* allow player to warp from right border to left border */
            break;
        default: /* Invalid input */
            /* Output message at the bottom */
            printf("\r\033[K");
            printf("\n'Please input a correct movement key'\n");

            /* Re-do input (to prevent updating game) */
            userInput = getUserInput();
            handlePlayerMovement(playerRow, playerCol, snakeRow, snakeCol, row, col, userInput);
            return; /* Return to avoid saving the state */
    }
}
