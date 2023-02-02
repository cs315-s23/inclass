PROG = eqsub
OBJS = eqsub.o eqsub_c.o eqsub_s.o

%.o: %.c
	gcc -c -g -o $@ $<

%.o: %.s
	as -g -o $@ $<

$(PROG): $(OBJS)
	gcc -g -o $(PROG) $(OBJS)

clean:
	rm -rf $(PROG) $(OBJS)
