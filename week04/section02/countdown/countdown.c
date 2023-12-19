#include <stdio.h>
#include <stdlib.h>

int countdown_c(int);
int countdown_s(int);

int main(int argc, char **argv) {
    int n = atoi(argv[1]);

    int cd_c = countdown_c(n);
    printf("C: %d\n", cd_c);

    int cd_s = countdown_s(n);
    printf("Asm: %d\n", cd_s);

    return 0;
}
