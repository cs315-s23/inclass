.global add1_s

# a0 contains the address of integers
# a1 contain the length of the array

# add1_s adds 1 to each array elem in place
add1_s:
    blt a1, zero, done
    lw t0, (a0)         # load the int value that a0. t0 == 5
    addi t0, t0, 1      # t0++
    sw t0, (a0)         # store new val out to orig addr
    addi a1, a1, -1     # len--
    addi a0, a0, 4      # walk a0 to next int
    j add1_s
done:
    ret
