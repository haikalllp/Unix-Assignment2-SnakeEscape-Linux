/* rules.c */
#include "rules.h"
#include <stdio.h>
#include <stdlib.h>

/* Modified from Assignment 1 */
/* Function to display rules of the game */
/* New Feature: uses Bold to improve readability */
void displayRules() {
    system("clear");
    printf("\n"); printf("\033[1m"); printf("WELCOME TO SNAKE ESCAPE!"); printf("\033[0m"); printf("\n\n");

    printf("\033[1m"); printf("Rules:"); printf("\033[0m"); printf("\n");
    printf("1. Control a "); printf("\033[1m"); printf("Player"); printf("\033[0m"); printf(" ("); printf("\033[1m"); printf("'P'"); printf("\033[0m"); printf(") to navigate the game board.\n");
    printf("2. Your goal is to guide the "); printf("\033[1m"); printf("Player"); printf("\033[0m"); printf(" to the "); printf("\033[1m"); printf("Food"); printf("\033[0m"); printf(" ("); printf("\033[1m"); printf("'@'"); printf("\033[0m"); printf(") for consumption.\n");
    printf("3. Beware of the "); printf("\033[1m"); printf("Snake"); printf("\033[0m"); printf(" ("); printf("\033[1m"); printf("'~'"); printf("\033[0m"); printf(") wandering the map. If it catches the "); printf("\033[1m"); printf("Player"); printf("\033[0m"); printf(", it's game over!\n");
    printf("4. Use the WASD keys to move the "); printf("\033[1m"); printf("Player"); printf("\033[0m"); printf(": "); printf("\033[1m"); printf("'W'"); printf("\033[0m"); printf(" (up), "); printf("\033[1m"); printf("'A'"); printf("\033[0m"); printf(" (left), "); printf("\033[1m"); printf("'S'"); printf("\033[0m"); printf(" (down), "); printf("\033[1m"); printf("'D'"); printf("\033[0m"); printf(" (right).\n");
    printf("5. Both "); printf("\033[1m"); printf("Player"); printf("\033[0m"); printf(" and "); printf("\033[1m"); printf("Snake"); printf("\033[0m"); printf(" can warp around map borders.\n");
    printf("6. "); printf("\033[1m"); printf("Player"); printf("\033[0m"); printf(" warps between left-right and top-bottom borders seamlessly.\n");
    printf("7. The "); printf("\033[1m"); printf("Snake"); printf("\033[0m"); printf(" 'may' warp unpredictably, so stay vigilant!\n");
    printf("8. If "); printf("\033[1m"); printf("Player"); printf("\033[0m"); printf(" gets too close to the "); printf("\033[1m"); printf("Snake"); printf("\033[0m"); printf(", it jumps to eat the "); printf("\033[1m"); printf("Player"); printf("\033[0m"); printf(".\n");
    printf("9. You can undo your move as well as the "); printf("\033[1m"); printf("Snake"); printf("\033[0m"); printf("'s move by pressing "); printf("\033[1m"); printf("'U'"); printf("\033[0m"); printf(" undo button.\n");
    printf("10. The game ends when either the "); printf("\033[1m"); printf("Player"); printf("\033[0m"); printf(" eats the "); printf("\033[1m"); printf("Food"); printf("\033[0m"); printf(" or gets eaten by the "); printf("\033[1m"); printf("Snake"); printf("\033[0m"); printf(".\n");
    printf("11. To win, consume the "); printf("\033[1m"); printf("Food"); printf("\033[0m"); printf(" without becoming "); printf("\033[1m"); printf("Snake"); printf("\033[0m"); printf(" food!\n\n");

    printf("Press '"); printf("\033[1m"); printf("Enter"); printf("\033[0m"); printf("' to continue...");
}
