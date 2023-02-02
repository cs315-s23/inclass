#include <stdio.h>
#include <stdlib.h>

int count_c(int);
int count_s(int);

int main(int argc, char **argv) {
    int val = atoi(argv[1]);

    int len = count_c(val);
    printf("C: %d\n", len);

    len = count_s(val);
    printf("Asm: %d\n", len);

    return 0;
}
