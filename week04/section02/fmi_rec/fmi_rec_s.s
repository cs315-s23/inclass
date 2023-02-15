.global fmi_rec_s

# a0: arr
# a1: len
# a2: idx
# a3: running max idx

fmi_rec_s:
    addi sp, sp, -8
    sd ra, (sp)

    mv t0, a3           # t0 is max idx
    ble a1, a2, done    # if len <= idx, done

    li t1, 4            # arr elem is 4 bytes
    mul t1, t1, a2      # t1 is offset
    add t1, t1, a0      # t1 is addr of idx offset
    lw t2, (t1)         # t2 is arr[idx]

    li t1, 4
    mul t1, t1, t0      # t1 is offset of max
    add t1, t1, a0      # t1 is addr of max offset
    lw t1, (t1)         # t1 is arr[max]

    ble t2, t1, recurse # if t1 is not a new max, recurse
    mv a3, a2           # new max idx

recurse:
    addi a2, a2, 1      # set up idx + 1
    call fmi_rec_s
    mv a3, a0
done:
    mv a0, a3           # cur max is still max
    ld ra, (sp)
    addi sp, sp, 8
    ret
