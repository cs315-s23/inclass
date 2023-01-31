.global add1_s

add1_s:
    # First arg is in a0
    # t0 = a0 + 1
    add t0, a0, 1      # t0 = a0 + immediate 1
    mv a0, t0           # set up return value in a0
    ret
