#include <stdio.h>
#include <stdlib.h>

int mul3_c(int);
int mul3_s(int);

int main(int argc, char **argv) {
    int num = atoi(argv[1]);

    int prod_c = mul3_c(num);
    printf("C: %d\n", prod_c);

    int prod_s = mul3_s(num);
    printf("Asm: %d\n", prod_s);

    return 0;
}
