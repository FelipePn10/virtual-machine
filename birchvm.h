#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef unsigned char int8;
typedef unsigned short int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $8 (int8 *)
#define $6 (int16)
#define $2 (int32)
#define $4 (int64)
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
    mov = 0x01, 
    nop = 0x02
};
typedef enum e_opcode Opcode;

struct s_instrmap {
    Opcode o;
    int8 size;
};
typedef struct s_intrmap IM;

typedef int8 Args;
struct s_instruction {
    Opcode o;
    Args a[]; /* 0-2 bytes */
};
typedef struct s_instruction Instruction;

typedef int8 Stack[((unsigned int)(-1))];
typedef Instruction Program;

struct s_vm {
     CPU c;
     Program *p;
};
typedef struct s_vm VM;

static Opcode opc;
static IM instrmap[] = {
    { mov, 0x03 },
    { nop, 0x01 }
};

int main(int,char**);