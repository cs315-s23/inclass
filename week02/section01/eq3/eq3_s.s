.global eq3_s

# a0 contains the number we want to compare with 3
# returns 1 if a0 == 3, else return 0

eq3_s:
    li t0, 3            # t0 = 3
    beq a0, t0, equal   # if a0 == 3, branch t0 equal
    li a0, 0
    j done 

equal:
    li a0, 1            # set up 1 (true) in a0
                        # fall through
done:
    ret
