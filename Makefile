flags=-O2 -Wall -std=c2x -IC:\Users\felip\projectC\virtual-machine\virtual-machine\birchutils\
#ldflags=-lbu
ldflags=

.PHONY: all clean

all: birchvm

C:\Users\felip\projectC\virtual-machine\virtual-machine\birchutils\birchutils.o: C:\Users\felip\projectC\virtual-machine\virtual-machine\birchutils\birchutils.c C:\Users\felip\projectC\virtual-machine\virtual-machine\birchutils\birchutils.h
	(cd C:\Users\felip\projectC\virtual-machine\virtual-machine\birchutils\birchutils.o && make)


birchvm: birchvm.o C:\Users\felip\projectC\virtual-machine\virtual-machine\birchutils/birchutils.o
	cc $(flags) $< -o $@ $(ldflags) C:\Users\felip\projectC\virtual-machine\virtual-machine\birchutils\birchutils.o

birchvm.o: birchvm.c birchvm.h
	cc $(flags) -c $< -o $@

clean:
	rm -f *.o birchvm