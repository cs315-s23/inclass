#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct emu_state {
    uint64_t regs[32];
    uint64_t pc;
};

#define A0 10
#define A1 11

void emu_init(struct emu_state *state, uint32_t *code, uint32_t a0, uint32_t a1) {
    memset(state, 0, sizeof(struct emu_state));
    state->pc = (uint64_t) code;
    state->regs[A0] = a0;
    state->regs[A1] = a1;
}

uint32_t get_bits(uint32_t num, uint32_t start, uint32_t count) {
    
}
void handle_r_type(struct emu_state *state, uint32_t iw) {
    uint32_t f3 = (iw >> 12) & 0b111;
    uint32_t f7 = (iw >> 25) & 0x7F;
    uint32_t rs1 = (iw >> 15) & 0x1F;
    uint32_t rs2 = (iw >> 20) & 0x1F;
    uint32_t rd = (iw >> 7) & 0x1F;

    if (f3 == 0 && f7 == 0) {
        // add instruction
        state->regs[rd] = state->regs[rs1] + state->regs[rs2];
    }
}

void handle_jalr(struct emu_state *state, uint32_t iw) {
    // jalr (jump and link register) puts the specified reg value into PC
    uint32_t rs1 = (iw >> 15) & 0x1F;
    uint32_t rd = (iw >> 7) & 0x1F;
    
    state->pc = state->regs[rs1];    
}

void emu_one(struct emu_state *state) {
    uint32_t iw = * (uint32_t*) (state->pc);
    uint32_t opcode = iw & 0b1111111;

    switch (opcode) {
        case 0b0110011: // R-type instruction
            handle_r_type(state, iw);
            break;
        case 0b1100111: // jalr
            handle_jalr(state, iw);
            break;
        default:
            printf("unknown instruction type\n");
    }
}

void emu_run(struct emu_state *state) {
    while (state->pc) {
        emu_one(state);
        if (state->pc)
            state->pc += 4;
    }
}

uint32_t add2_s(uint32_t, uint32_t);

int main(int argc, char **argv) {
    uint32_t a = atoi(argv[1]);
    uint32_t b = atoi(argv[2]);

    uint32_t s_sum = add2_s(a, b);
    printf("Asm: %d\n", s_sum);

    uint32_t *pcode = (uint32_t*) add2_s;
    struct emu_state state;
    emu_init(&state, pcode, a, b);

    emu_run(&state);
    printf("Emu: %ld\n", state.regs[A0]);
    
    return 0;
}
