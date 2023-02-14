.global fact_s

fact_s:
    addi sp, sp, -16     # prologue
    sd ra, (sp)
    sd a0, 8(sp)

    li t1, 1            # base case
    ble a0, t1, done

    sub a0, a0, t1      # set up n-1 for recursive case
    call fact_s
    mv t0, a0           # set ret val aside
    ld a0, 8(sp)
    mul a0, a0, t0      # n * ret val
done:
    ld ra, (sp)         # epilogue
    addi sp, sp, 16
    ret
