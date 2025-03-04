CC := gcc
CFLAGS := -O2 -Wall -std=c2x
LDFLAGS :=

# Caminho correto para birchutils
UTILS_PATH := birchutils/birchutils
UTILS_SRC := $(UTILS_PATH)/birchutils.c
UTILS_OBJ := $(UTILS_PATH)/birchutils.o

VM_SRC := birchvm.c
VM_OBJ := birchvm.o
OBJS := $(VM_OBJ) $(UTILS_OBJ)

.PHONY: all clean

all: birchvm

$(UTILS_OBJ): $(UTILS_SRC) $(UTILS_PATH)/birchutils.h
	$(CC) $(CFLAGS) -c $< -o $@

birchvm: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

birchvm.o: birchvm.c birchvm.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o birchvm $(UTILS_OBJ)
