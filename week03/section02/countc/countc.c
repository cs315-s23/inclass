#include <stdio.h>
#include <stdlib.h>

int countc_c(char *, int);
int countc_s(char *, int);

/* count the occurrences of a char in a string
   argv[1] is the string
   argv[2] contains the char
*/
int main(int argc, char **argv) {
    char *str = argv[1];
    char ch = argv[2][0];

    int c_count = countc_c(str, ch);
    printf("C: %d\n", c_count);

    int s_count = countc_s(str, ch);
    printf("Asm: %d\n", s_count);

    return 0;
}
