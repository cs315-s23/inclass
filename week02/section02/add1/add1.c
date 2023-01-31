#include <stdio.h>
#include <stdlib.h>

int add1_c(int);
int add1_s(int);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("usage: add1 num1\n");
        exit(-1);
    }

    int num1 = atoi(argv[1]);

    int c_sum = add1_c(num1);
    printf("C: %d\n", c_sum);

    int s_sum = add1_s(num1);
    printf("Asm: %d\n", s_sum);

    return 0;
}
