#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "birchutils/birchutils/birchutils.h"

#pragma GCC diagnostic ignored "-Wstringop-truncation"
#pragma GCC diagnostic ignored "-Wformat-truncation="
#pragma GCC diagnostic push

#define ErrMem      0x01
#define NoArgs      { 0x00, 0x00 }

typedef unsigned char int8;
typedef unsigned short int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $c (char *)
#define $i (int)

/*
    16 bit
        AX
        BX
        CX
        DX
        SP
        IP
    65 KB memory
    (Serial COM port)
    (Floppy drive)

    AX, BX, CX, DX are general purpose registers.
    SP (Stack Pointer) stores the address of the top of the stack.
    IP (Instruction Pointer) holds the address of the next instruction to be executed.

    CPU registers will be 16 bits wide.
*/


typedef unsigned short int Reg;
struct s_registers {
    Reg ax;
    Reg bx;
    Reg cx;
    Reg dx;
    Reg sp;
    Reg ip;
};
typedef struct s_registers Registers;
//Register Set
struct s_cpu {
    Registers r;
};
typedef struct s_cpu CPU;

/*
    mov ax, 0x05 // (0x01 OR ax)
                 // 0000 0011 = mov
                 // 0000 0000
                 // 000 0000 = 0x05
*/

enum e_opcode {
    mov = 0x01,  // operation to move values between registers.
    nop = 0x02 
};
typedef enum e_opcode Opcode;

// Instruction mapping structure
// Helps the CPU interpret how many bytes it needs to read for each instruction.
struct s_instrmap {
    Opcode o;
    int8 s;
};
typedef struct s_instrmap IM;

typedef int8 Args;
// Represents a CPU command, storing different instructions and their parameters
struct s_instruction {
    Opcode o;
    Args a[]; /* 0-2 bytes */
};
typedef struct s_instruction Instruction;

typedef int8 Memory[((unsigned int)(-1))];
typedef int8 Program;

struct s_vm {
     CPU c;
     Memory m;
     Program *p;
};
typedef struct s_vm VM;
typedef Memory *Stack;

static IM instrmap[] = {
    { mov, 0x03 },
    { nop, 0x01 }
};
#define IMs (sizeof(instrmap) / sizeof(struct s_instrmap))

Program *exampleprogram(VM*);
int8 map(Opcode);
VM *virtualmachine(void);
int main(int,char**);