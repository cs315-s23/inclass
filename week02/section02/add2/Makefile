PROG = add2
OBJS = add2.o add2_c.o add2_s.o

# pattern rules to build .o files from source
%.o: %.c
	gcc -c -g -o $@ $<

%.o: %.s
	as -g -o $@ $<

$(PROG): $(OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROG) $(OBJS)
