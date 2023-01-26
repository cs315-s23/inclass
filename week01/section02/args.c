#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    for (int i = 0; i < argc; i++) 
        printf("argv[%d] = \"%s\"\n", i, argv[i]);

    int base = atoi(argv[1]);
    printf("base = %d\n", base);

    return 0;
}
