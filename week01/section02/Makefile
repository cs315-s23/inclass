# Make variables for executable name and .o object files
PROG = args
OBJS = args.o printit.o

# Pattern rules for C and assembly language
%.o: %.c
	gcc -g -c -o $@ $<

%.o: %.s
	as -g -o $@ $<

# Link object files together into executable
$(PROG): $(OBJS)
	gcc -g -o $@ $^

# Delete all the build products
clean:
	rm -rf $(PROG) $(OBJS)
