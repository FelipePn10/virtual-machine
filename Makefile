flags=-O2 -Wall -std=c2x
ldflags=-lbu

.PHONY: all clean

all: clean birchvm

birchvm: birchvm.o
	cc $(flags) $^ -o $@ $(ldflags)

birchvm.o: birchvm.c
	cc $(flags) -c $< -o $@

clean:
	rm -f *.o birchvm
