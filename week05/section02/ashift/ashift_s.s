.global ashift_s

# a0: arr
# a1: len

ashift_s:
    li t0, 0                # t0 is loop index
loop:
    bge t0, a1, done        # reached end of arr?
    slli t1, t0, 2          # t1 is the offset of i'th elem
    add t1, a0, t1          # t1 is the addr of i'th elem    
    lw t2, (t1)             # t2 is the value of arr[i]
    sraiw t2, t2, 3         # t2 >>= 3
    sw t2, (t1)             # arr[i] = t2
    addi t0, t0, 1          # loop index++
    j loop
done:
    ret
