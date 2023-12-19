#include <stdio.h>

// iterative solution to countdown timer
// using a loop which counts down

int main(int argc, char **argv) {
    for (int i = 10; i > -1; i--) {
        printf("%d\n", i);
        if (i == 1) {
            printf("blast off!\n");
        }
    }
}
