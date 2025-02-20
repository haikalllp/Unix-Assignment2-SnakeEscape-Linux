/* gameSavesLL.c */

#include "gameSavesLL.h"
#include <stdlib.h>

/* Reference: Unix and C Programming Lecture */
/* Push a new game state onto the linked list (utilizes stack method) */
void saveGameState(GameState** head, int playerRow, int playerCol, int snakeRow, int snakeCol) {
    /* Allocate memory for the new game state */
    GameState* newState = (GameState*)malloc(sizeof(GameState));
    if (newState == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    /* Assign values to the new game state */
    newState->playerRow = playerRow;
    newState->playerCol = playerCol;
    newState->snakeRow = snakeRow;
    newState->snakeCol = snakeCol;
    /* Update the linked list pointers */
    newState->next = *head;
    *head = newState;
}

/* Reference: Unix and C Programming Lecture */
/* Pop the last game state from the linked list (utilizes stack method) */
void retrieveGameState(GameState** head, int* playerRow, int* playerCol, int* snakeRow, int* snakeCol) {
    GameState* temp;
    /* Check if the linked list is empty */
    if (*head == NULL) {
        return;
    }
    /* Pop the last game state from the linked list */
    temp = *head;
    /* Retrieve values from the popped game state */
    *playerRow = temp->playerRow;
    *playerCol = temp->playerCol;
    *snakeRow = temp->snakeRow;
    *snakeCol = temp->snakeCol;
    /* Update the linked list head pointer */
    *head = (*head)->next;
    /* Free memory allocated for the popped game state */
    free(temp);
}

/* Check if the linked list is empty */
int isEmpty(GameState* head) {
    return head == NULL;
}

/* Reference: Unix and C Programming Lecture */
/* Free the linked list */
void freeList(GameState* head) {
    GameState* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
