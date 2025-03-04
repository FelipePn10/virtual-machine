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

.PHONY: all clean test

all: birchvm

# Compile utils library
$(UTILS_OBJ): $(UTILS_PATH)/birchutils.c $(UTILS_PATH)/birchutils.h
	$(CC) $(CFLAGS) -c $< -o $@

# Compile virtual machine
birchvm: $(VM_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(VM_OBJ) $(UTILS_OBJ) -o $@ $(LDFLAGS)

# Compile birchvm object file
birchvm.o: birchvm.c birchvm.h
	$(CC) $(CFLAGS) -c $< -o $@

# Test target
test: birchvm
	./birchvm testfile.vm

# Clean up
clean:
	rm -f *.o birchvm $(UTILS_OBJ)
