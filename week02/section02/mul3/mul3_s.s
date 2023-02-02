.global mul3_s

# a0 contains the number we want to multiply by 3

mul3_s:
    li t0, 3            # t0 = 3. "t" regs are temporary. writable without saving
    mul a0, a0, t0      # multiply param a0 * 3, into a0
                        # a0 *= 3
    ret
