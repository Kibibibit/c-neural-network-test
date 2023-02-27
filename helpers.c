#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "typedefs.h"

void assert(boolean expression, char * message) {
    if (!expression) {
        printf(message);
        exit(1);
    }
}