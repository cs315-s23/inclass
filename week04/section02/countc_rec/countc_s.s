.global countc_s

countc_s:
    lb t0, (a0)         # base case
    bne t0, zero, recurse
    mv a0, zero
    ret

recurse:
    
    addi sp, sp, -16    # prologue
    sd ra, (sp)         # preserve ra
    sd t0, 8(sp)        # preserve *s

    addi a0, a0, 1      # setup s + 1
    call countc_s
    ld t0, 8(sp)        # restore *s
    beq t0, a1, match
    j not_match
match:
    addi a0, a0, 1      # new_count++
not_match:
    ld ra, (sp)         # epilogue
    addi sp, sp, 16     # dealloc stack space
    ret
