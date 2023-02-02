#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool istrue_c(bool);
bool istrue_s(bool);

int main(int argc, char **argv) {
    bool b = atoi(argv[1]);

    if (istrue_c(b))
        printf("C: true\n");
    else
        printf("C: false\n");

    if (istrue_s(b))
        printf("Asm: true\n");
    else
        printf("Asm: false\n");

    return 0;    
}
