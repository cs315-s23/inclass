.global fact_s

fact_s:
    addi sp, sp, -16
    sd ra, (sp)
    sd a0, 8(sp)

    li t0, 1
    ble a0, t0, done

    sub a0, a0, t0      # set up n-1 in a0
    call fact_s
    ld a1, 8(sp)        # a1 is orig n
    mul a0, a0, a1      # a0 = ret val * orig n
done:
    ld ra, (sp)
    addi sp, sp, 16
    ret
