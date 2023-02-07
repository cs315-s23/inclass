.global add1_s

# a0 contains the address of an integer
# add1_s adds 1 to that value in place
add1_s:
    lw t0, (a0)         # load the int value that a0. t0 == 5
    addi t0, t0, 1      # t0 == 6
    sw t0, (a0)         # store 6 out to orig addr
    ret
