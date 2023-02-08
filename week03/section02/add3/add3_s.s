.global add3_s

# a0 contains a
# a1 contains b
# return sum in a0
add2_s:
    add a0, a0, a1
    ret

# a0 = a, a1 = b, a2 = c 
# call add2_s twice and return the sum  
add3_s:
    addi sp, sp, -8     # prologue
    sd ra, (sp)

    call add2_s
    mv a1, a2           # set up "c" for add2_s
    call add2_s

    ld ra, (sp)         # epilogue
    addi sp, sp, 8
    ret
