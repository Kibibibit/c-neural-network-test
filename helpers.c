#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "helpers.h"
#include "typedefs.h"
#include "constants.h"

void assert(boolean expression, char * message) {
    if (!expression) {
        printf(message);
        exit(EXIT_ASSERT_FAILED);
    }
}

float randomFloat(float min, float max) {

    

    float scale = rand() / (float) RAND_MAX;

    return min + scale*(max-min);

}