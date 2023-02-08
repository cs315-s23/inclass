.global add3_s


# a0 = a, a1 = b, returns sum
add2_s:
    add a0, a0, a1      # a0 = a0 + a1    
    ret

# a0 = a, a1 = b, a2 = c, returns sum
add3_s:
    addi sp, sp, -8     # prologue
    sd ra, 0(sp)
    
    call add2_s
    mv a1, a2           # set up param for add2_s
    call add2_s

    ld ra, 0(sp)        # epilogue
    addi sp, sp, 8

    ret
