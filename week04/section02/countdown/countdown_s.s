.global countdown_s

# a0: the number of times to count down
countdown_s:
    addi sp, sp, -8         # prologue
    sd ra, (sp)

    beq a0, zero, done      # base case

    addi a0, a0, -1         # set up n -1 for recursion
    call countdown_s

done:
    ld ra, (sp)             # epilogue
    add sp, sp, 8
    ret
