#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool eq3_c(int);
bool eq3_s(int);

int main(int argc, char **argv) {
    int num = atoi(argv[1]);

    if (eq3_c(num))
        printf("C: equal\n");
    else
        printf("C: not equal\n");

    if (eq3_s(num))
        printf("Asm: equal\n");
    else
        printf("Asm: not equal\n");

    
}
