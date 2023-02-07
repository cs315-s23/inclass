.global slen_s

# a0 contains the pointer to chars
# returns length

slen_s:
    mv t1, zero             # init len to 0
loop:
    lb t0, (a0)             # t0 = *a0
    beq t0, zero, done      # reached null term?
    addi t1, t1, 1          # increment len
    addi a0, a0, 1          # walk s forward
    j loop                  # go again

done:
    mv a0, t1               # set up len in a0
    ret
