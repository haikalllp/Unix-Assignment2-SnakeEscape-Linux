/* sleep.c */

#define _DEFAULT_SOURCE
#include "sleep.h"
#include <time.h>

/* Reference: Supplementary video */
/* Function to add delay */
void delay(float sec) {
    struct timespec ts;
    ts.tv_sec = (int) sec;
    ts.tv_nsec = (sec - ((int) sec)) * 1000000000;
    nanosleep(&ts,NULL);
}
