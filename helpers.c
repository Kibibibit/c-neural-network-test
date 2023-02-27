#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "typedefs.h"
#include "constants.h"

void assert(boolean expression, char * message) {
    if (!expression) {
        printf(message);
        exit(EXIT_ASSERT_FAILED);
    }
}