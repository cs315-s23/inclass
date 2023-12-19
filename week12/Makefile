OBJS = part1.o part2.o
HEX = part1.hex part2.hex

%.o: %.s
	as -o $@ $<

%.hex: %.o
	objdump -d $< | python3 makerom3.py > $@

all: $(HEX)
