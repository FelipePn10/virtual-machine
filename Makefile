# Compiler and flags
CC := gcc
CFLAGS := -O2 -Wall -std=c2x -I$(VMPATH)/birchutils
LDFLAGS :=

# Paths
VMPATH := ./virtual-machine
UTILS_PATH := $(VMPATH)/birchutils

# Objects
UTILS_OBJ := $(UTILS_PATH)/birchutils.o
VM_OBJ := birchvm.o
flags=-O2 -Wall -std=c2x -IC:\Users\felip\projectC\virtual-machine\virtual-machine\birchutils\
#ldflags=-lbu
ldflags=

.PHONY: all clean test

all: birchvm

C:\Users\felip\projectC\virtual-machine\virtual-machine\birchutils\birchutils.o: C:\Users\felip\projectC\virtual-machine\virtual-machine\birchutils\birchutils.c C:\Users\felip\projectC\virtual-machine\virtual-machine\birchutils\birchutils.h
	(cd C:\Users\felip\projectC\virtual-machine\virtual-machine\birchutils\birchutils.o && make)


# Compile birchvm object file
birchvm.o: birchvm.c birchvm.h
	$(CC) $(CFLAGS) -c $< -o $@

# Test target
test: birchvm
	./birchvm testfile.vm

# Clean up
clean:
	rm -f *.o birchvm $(UTILS_OBJ)
birchvm: birchvm.o C:\Users\felip\projectC\virtual-machine\virtual-machine\birchutils/birchutils.o
	cc $(flags) $< -o $@ $(ldflags) C:\Users\felip\projectC\virtual-machine\virtual-machine\birchutils\birchutils.o

birchvm.o: birchvm.c birchvm.h
	cc $(flags) -c $< -o $@

clean:
	rm -f *.o birchvm
