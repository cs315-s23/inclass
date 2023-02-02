#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool eqsub_c(int, int);
bool eqsub_s(int, int);

int main(int argc, char **argv) {
    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);

    if (eqsub_c(n1, n2))
        printf("C: True\n");
    else
        printf("C: False\n");
        
    if (eqsub_s(n1, n2))
        printf("Asm: True\n");
    else
        printf("Asm: False\n");
        
    return 0;
}
