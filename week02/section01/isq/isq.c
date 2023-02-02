#include <stdio.h>
#include <stdbool.h>

bool isq_c(char ch);
bool isq_s(char ch);

int main(int argc, char **argv) {
    char ch = argv[1][0];

    if (isq_c(ch))
        printf("C: is q\n");
    else
        printf("C: is not q\n");
        
    if (isq_s(ch))
        printf("Asm: is q\n");
    else
        printf("Asm: is not q\n");
        
    return 0;
}
