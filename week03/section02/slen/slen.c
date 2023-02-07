#include <stdio.h>

int slen_c(char*);
int slen_s(char*);

int main(int argc, char **argv) {
    char *s = argv[1];

    int c_len = slen_c(s);
    printf("C: %d\n", c_len);

    int s_len = slen_s(s);
    printf("Asm: %d\n", s_len);

    return 0;
}
