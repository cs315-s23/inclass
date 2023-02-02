.global isq_s

# a0 contains the char we want to match with 'q'

isq_s:
    li t0, 113          # ASCII 'q'
    beq a0, t0, is_equal
    # not taken
    li a0, 0            # set up 0 (false) in a0 ret val
    ret
is_equal:
    # taken
    li a0, 1            # set up 1 (true) in a0 ret val
done:
    ret
    
