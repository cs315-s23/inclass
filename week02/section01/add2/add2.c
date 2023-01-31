#include <stdio.h>
#include <stdlib.h>

int add2_c(int, int);
int add2_s(int, int);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("usage: add2 num1 num2\n");
        exit(-1);
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    int c_sum = add2_c(num1, num2);
    printf("C: %d\n", c_sum);

    int s_sum = add2_s(num1, num2);
    printf("Asm: %d\n", s_sum);

    return 0;
}
