.global eqsub_s

# a0 and a1 contain integer arguments for the subtraction

eqsub_s:
    sub t0, a0, a1      # t0 = n1 - n2
    li t1, 10           # t1 = 10
    beq t0, t1, equal   # if t0 == t1, branch to equal
    li a0, 0            # set up 0 (false) in a0
    j done
equal:
    li a0, 1            # set up 1 (true) in a0
done:
    ret
