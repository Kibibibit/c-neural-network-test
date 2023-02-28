#include "graphs.h"
#include "constants.h"
#include <math.h>

float sigmoid(float x)
{
    return 1.0 / (1.0 + (powf(EULER, -1.0 * x)));
}