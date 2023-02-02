.global loop_s

loop_s:
    li t0, 0            # initialize the ret val

loop:
    beq a0, zero, done  # if count != 0
    addi t0, t0, 1      # increment ret val
    li t2, 1
    sub a0, a0, t2      # a0 = a0 - t2 (1)
    j loop              # go again

done:
    mv a0, t0           # set up ret val in a0
    ret
