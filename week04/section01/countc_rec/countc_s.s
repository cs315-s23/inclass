.global countc_s

countc_s:
    lb t0, (a0)             # t0 = *s
    bne t0, zero, recurse   # reached null term
    mv a0, zero
    ret
    
recurse:
    addi sp, sp, -16        # alloc stack space
    sd ra, (sp)             # preserve ra
    sd t0, 8(sp)            # preserve t0

    addi a0, a0, 1          # set up s + 1
    call countc_s
    ld t0, 8(sp)            # restore *s into t0
    bne t0, a1, done        # *s == c?
    addi a0, a0, 1          # new_count++
done:
    ld ra, (sp)             # restore ra
    addi sp, sp, 16         # dealloc stack space
    ret
