#include <stdio.h>
#include <stdlib.h>

int loop_c(int);
int loop_s(int);

int main(int argc, char ** argv) {
    int count = atoi(argv[1]);

    int c_count = loop_c(count);
    printf("C: %d\n", c_count);

    int s_count = loop_s(count);
    printf("Asm: %d\n", s_count);

    return 0;
}
