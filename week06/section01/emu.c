#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t add2_s(uint32_t, uint32_t);

int main(int argc, char **argv) {
    uint32_t a = atoi(argv[1]);
    uint32_t b = atoi(argv[2]);

    uint32_t s_sum = add2_s(a, b);

    printf("Asm: %d\n", s_sum);

    uint32_t *add2_ptr = (uint32_t*) add2_s;
    uint32_t iw = *add2_ptr;
    printf("iw: %x\n", iw);

    uint32_t rd = (iw >> 7) & 0x1f; // 0x1f == 0b11111
    printf("rd: %d\n", rd);
    
    uint32_t rs1 = (iw >> 15) & 0x1f;
    printf("rs1: %d\n", rs1);
    
    return 0;
}
