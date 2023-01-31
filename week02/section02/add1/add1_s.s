.global add1_s

add1_s:
    addi t0, a0, 1      # t0 = a0 + 1
    mv a0, t0           # set up ret val in a0
    ret                 # return
