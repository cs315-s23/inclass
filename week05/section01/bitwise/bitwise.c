#include <stdio.h>
#include <stdlib.h>

int and_c(int, int);
int and_s(int, int);

int main(int argc, char **argv) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int c_result = and_c(a, b);
    printf("C: %d\n", c_result);

    int s_result = and_s(a, b);
    printf("Asm: %d\n", s_result);

    return 0;
}
