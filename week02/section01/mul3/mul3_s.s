.global mul3_s

# a0 contains the num to multiply by 3

mul3_s:
    li t0, 3                # set up operand to multiply
    mul a0, a0, t0          # a0 = a0 * t0
    ret
