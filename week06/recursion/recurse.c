#include <stdio.h>

void countdown(int i) {
    // base case
    if (i == 0) {
        printf("blast off\n");
    } else {
        // recursive case: decompose data,
        // call ourselves again
        printf("%d\n", i);
        countdown(i - 1);
    }
}

int main(int argc, char **argv) {
    countdown(10);
    return 0;
}
