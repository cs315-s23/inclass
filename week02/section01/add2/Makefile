PROG = add2
OBJS = add2.o add2_c.o add2_s.o

%.o: %.c
	gcc -c -g -o $@ $<		# gcc -c -g -o add2.o add2.c

%.o: %.s
	as -g -o $@ $<			# as -g -o add2_s.o add2_s.s

$(PROG): $(OBJS)
	gcc -g -o $@ $^			# link all objs into executable

clean:
	rm -rf $(PROG) $(OBJS)
