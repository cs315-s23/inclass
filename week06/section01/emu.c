#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint32_t add2_s(uint32_t, uint32_t);

struct emu_state {
    uint64_t regs[32];
    uint64_t pc;
};

#define A0 10
#define A1 11

void emu_init(struct emu_state *state, uint64_t code, uint64_t a0, uint64_t a1) {
    memset(state, 0, sizeof(struct emu_state));
    state->pc = code;
    state->regs[A0] = a0;
    state->regs[A1] = a1;
}

void handle_r_type(struct emu_state *state, uint32_t iw) {
    uint32_t rd = (iw >> 7) & 0x1F;
    uint32_t rs1 = (iw >> 15) & 0x1F;
    uint32_t rs2 = (iw >> 20) & 0x1F;
    uint32_t f3 = (iw >> 12) & 0b111;
    uint32_t f7 = (iw >> 25) & 0x7F;
    
    if (f3 == 0 && f7 == 0) {
        // add instruction
        state->regs[rd] = state->regs[rs1] + state->regs[rs2];
    }
}

void handle_jalr(struct emu_state *state, uint32_t iw) {
    // pc = ra, where ra is named in rs1
    uint32_t rs1 = (iw >> 15) & 0x1F;
    state->pc = state->regs[rs1];
}

void emu_one(struct emu_state *state) {
    // typecast pc to a pointer to uint32_t's
    uint32_t *code = (uint32_t *) state->pc;

    // dereference pc to get the first instr word at that addr
    uint32_t iw = *code;
    uint32_t opcode = iw & 0b1111111;
    switch (opcode) {
        case 0b0110011:  // r-type instruction
            handle_r_type(state, iw);
            break;
        case 0b1100111: // jalr
            handle_jalr(state, iw);
            break;
        default:
            printf("unknown opcode %d\n", opcode);
    }
}

void emu_run(struct emu_state *state) {
    while (state->pc != 0) {
        emu_one(state);
        if (state->pc != 0)
            state->pc += 4;
    }
}

int main(int argc, char **argv) {
    uint32_t a = atoi(argv[1]);
    uint32_t b = atoi(argv[2]);

    uint32_t s_sum = add2_s(a, b);
    printf("Asm: %d\n", s_sum);

    struct emu_state state;
    emu_init(&state, (uint64_t) add2_s, a, b);
    emu_run(&state);

    uint32_t e_sum = state.regs[A0];
    printf("Emu: %d\n", e_sum);
    return 0;
}
