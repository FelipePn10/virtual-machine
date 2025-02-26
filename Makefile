# Compiler and flags
CC = gcc
CFLAGS = -O2 -Wall -std=c11
LDFLAGS = 

# Paths
VMPATH = C:/Users/felip/projectC/virtual-machine/virtual-machine
UTILS_PATH = $(VMPATH)/birchutils

# Objects
UTILS_OBJ = $(UTILS_PATH)/birchutils.o
VM_OBJ = birchvm.o

.PHONY: all clean

# Main build target
all: birchvm

# Compile utils library
$(UTILS_OBJ): $(UTILS_PATH)/birchutils.c $(UTILS_PATH)/birchutils.h
	$(CC) $(CFLAGS) -c $< -o $@

# Compile virtual machine
birchvm: $(VM_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(VM_OBJ) $(UTILS_OBJ) -o $@ $(LDFLAGS)

# Compile birchvm object file
birchvm.o: birchvm.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean generated files
clean:
	@if exist *.o del /F /Q *.o
	@if exist birchvm del /F /Q birchvm
	@if exist $(UTILS_OBJ) del /F /Q $(UTILS_OBJ)
