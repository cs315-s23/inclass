.global slen_s

# a0 contains a string (addr of first char)
# slen_s returns its length

slen_s:
    li t1, 0            # len = 0
loop:
    lb t0, 0(a0)        # t0 = *a0
    beq t0, zero, done  # reached null terminator?
    addi t1, t1, 1      # increment len
    addi a0, a0, 1      # increment s (s++)
    j loop
done:
    mv a0, t1           # set up len ret val in a0
    ret
