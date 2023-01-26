#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0) {
            printf("base is %s\n", argv[i+1]);
        }
        //printf("argv[%d] = \"%s\"\n", i, argv[i]);
    }

    return 0;
}
