.global istrue_s

# a0 is the value. return 1 if a0 is 1, return 0 if a0 is 0

istrue_s:
    li t0, 1                # load "true" (1) into t0
    beq a0, t0, done        # if a0 == 1, nothing to do
    li a0, 0                # if a0 != 1, set up 0 in a0
done:
    ret
