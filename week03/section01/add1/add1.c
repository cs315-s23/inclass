#include <stdio.h>

void add1_c(int*);
void add1_s(int*);

int main() {
    int i = 5;

    add1_c(&i);
    printf("C: %d\n", i);

    i = 5;
    add1_s(&i);
    printf("Asm: %d\n", i);

    return 0;
}
