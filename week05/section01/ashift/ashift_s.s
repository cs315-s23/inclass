.global ashift_s

# a0: arr
# a1: count
ashift_s:
    li t0, 0            # t0 is loop index
loop:
    beq t0, a1, done    # reached count?

    slli t1, t0, 2      # t1 is the offset of i'th elem
    add t1, a0, t1      # t1 is the addr of i'th elem
    lw t2, (t1)         # t2 is the int val of arr[i]

    sraiw t2, t2, 2     # >> 2
    sw t2, (t1)         # store mutated val to addr of i'th elem

    addi t0, t0, 1      # loop index++
    j loop
done:
    ret
