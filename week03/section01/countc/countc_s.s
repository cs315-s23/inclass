.global countc_s

# findc_s returns the index of a1 (ch) in a0 (str)
findc_s:
    li t1, 0                # t1 is the index
loop:
    lb t0, (a0)             # t0 = *a0
    beq t0, zero, find_term # reached null terminator?
    beq t0, a1, find_done   # t0 == ch?
    addi t1, t1, 1          # increment index
    addi a0, a0, 1          # walk str to next char
    j loop                  # go again

find_term:
    li t1, -1               # if found null terminator, return -1
find_done:
    mv a0, t1               # set up index in a0 ret val
    ret

# countc_s returns the count of a1 (ch) in a0 (str)
countc_s:
    addi sp, sp, -8         # prologue
    sd ra, (sp)

    li t0, 0                # t0 countains the count
    li t2, -1               # t2 contains -1 for comparison
count_loop:
    lb t1, (a0)             # t1 = *str
    beq t1, zero, count_done# reached null term?

    mv t3, a0               # save a0? icky?
    addi sp, sp, -24
    sd t0, (sp)             # preserve t0
    sd t1, 8(sp)            # preserve t1
    sd t3, 16(sp)
    call findc_s
    ld t0, (sp)             # restore t0
    ld t1, 8(sp)            # restore t1
    ld t3, 16(sp)
    addi sp, sp, 24

    beq a0, t2, count_done  # break if no more matches
    addi t0, t0, 1          # count++

    add t3, t3, a0          # add idx to str
    addi t3, t3, 1          # add 1 to str
    mv a0, t3               # put a0 back    
    j count_loop

count_done:
    mv a0, t0               # set up count ret val in a0
    ld ra, (sp)             # epilogue
    addi sp, sp, 8
    ret
