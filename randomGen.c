/* randomGen.c */

#include "randomGen.h"
#include <stdlib.h>
#include <time.h>

/* Reference: Suplementary video */
/* Function to generate random number */
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}
