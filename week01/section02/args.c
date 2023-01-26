#include <stdio.h>
#include <stdlib.h>

void printit(char *s);

int main(int argc, char **argv) {
    for (int i = 0; i < argc; i++) 
        printf("argv[%d] = \"%s\"\n", i, argv[i]);

    int base = atoi(argv[1]);
    printf("base = %d\n", base);

    printit("print this!\n");
    
    return 0;
}
