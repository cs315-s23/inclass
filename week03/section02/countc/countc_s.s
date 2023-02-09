.global countc_s

# a0 = str
# a1 = ch to find
# returns index of ch, or -1 if not found
findc_s:
    li t1, 0                        # t1 is the index
find_loop:
    lb t0, (a0)                     # t0 = *str
    beq t0, zero, not_found         # null terminator?
    beq t0, a1, set_index           # matches ch?
    addi t1, t1, 1                  # increment index
    addi a0, a0, 1                  # walk str to next char
    j find_loop                     # go again
not_found:
    li t1, -1
set_index:
    mv a0, t1                       # set up index in ret val
    ret

# a0 = str
# a1 = ch
countc_s:
    mv t0, zero                     # initialize count
    addi sp, sp, -8                 # alloc 8 bytes on stack
    sd ra, (sp)                     # preserve ra

count_loop:
    addi sp, sp, -16
    sd t0, 0(sp)                    # preserve t0
    sd a0, 8(sp)
    call findc_s
    ld t0, (sp)                     # restore t0
    mv t3, a0                       # put findc_s ret val in t3
    ld a0, 8(sp)                    # restore a0
    addi sp, sp, 16
    li t1, -1                       # setup "not found"
    beq t3, t1, index_not_found
    add a0, a0, t3                  # str += index
    addi a0, a0, 1                  # str += 1
    addi t0, t0, 1                  # count++
    j count_loop
    
index_not_found:
    mv a0, t0                       # set up count ret val
    
    ld ra, (sp)                     # restore ra
    add sp, sp, 8                   # deallocate stack space
    ret
