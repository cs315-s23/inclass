.global count_s

count_s:
    li t0, 0            # init counter

loop:
    beq a0, zero, done  # is val > 0?
    addi t0, t0, 1      # increment counter
    addi a0, a0, -1     # decrement val
    j loop

done:
    mv a0, t0           # set up count in a0
    ret
