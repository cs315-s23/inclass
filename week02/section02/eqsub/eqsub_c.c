#include <stdbool.h>

// eqsub returns true if a - b == 10

bool eqsub_c(int a, int b) {
    int diff = a - b;

    if (diff == 10) 
        return true;

    return false;
}
