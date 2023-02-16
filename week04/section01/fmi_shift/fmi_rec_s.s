.global fmi_rec_s

fmi_rec_s:
    addi sp, sp, -8
    sd ra, (sp)

    mv t0, a3           # t0 holds the max idx
    ble a1, a2, done    # len <= idx

    slli t2, a2, 2      # t2 is the offset of idx'th elem
    add t2, a0, t2      # t2 is addr of the idx'th elem
    lw t2, (t2)         # t2 is arr[idx]

    slli t3, a3, 2      # t3 is the offset of the max'th elem
    add t3, a0, t3      # t3 is the add of the max'th elem
    lw t3, (t3)         # t3 is arr[max]

    ble t2, t3, recurse # new max?
    mv t0, a2           # set up new max in t0
recurse:
    mv a3, t0           # set up max_new param
    addi a2, a2, 1      # set up idx + 1 in a2
    call fmi_rec_s
    mv t0, a0           # set up max value into t0
done:
    mv a0, t0           # set up ret val
    ld ra, (sp)
    addi sp, sp, 8
    ret
