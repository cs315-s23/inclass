.global add2_s

add2_s:
    # First arg is in a0
    # Second arg is in a1
    # t0 = a0 + a1
    add t0, a0, a1      # t0 = a0 + a1
    mv a0, t0           # set up return value in a0
    ret
