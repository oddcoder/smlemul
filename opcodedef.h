#ifndef _OPCODEDEF_H
#define _OPCODEDEF_H
#define HALT 0x100
//program ends
//HALT  
#define READ 0x1000 
//2 byte from terminal in hex
//READ MEMADRESS
#define READAX 0x1100
//2 byte hard// ax and memcoded into ax
#define WRITE 0x2000
//write 2 byte from memory to terminal 
//WRITE MEMADRESS
#define LOAD 0x2100
//load 2 byte from memory to ax 
#define STOR 0x2200
//store 2 byte from ax to memory 
#define STORE 0x2201
//same as stor but for ex
#define ADDM 0x3000
// adds 2 bytes from memory to ax and store resault in ax
#define ADD 0x3001
// adds 2 hardocoded bytes to ax and store resault in ax
#define SUBM 0x3100
//acc- mem
#define SUB 0x3101
//acc - hardcoded
#define DIVM 0x3200
// ax = ax / mem
// ex = ax % mem
#define DIV 0x3201
// ax = ax/  hardcoded
// ex = ax % hardcoded 
#define MULM 0x3300
//ex:ax = ax*mem
#define MUL 0x3301
//ex:ax = ax*hardocded
#define JMP 0x4000
// unconditional jump
#define JN 0x4100
//jump if accumulator is negative
#define JZ  0x4200
//jump if accumulator is zero
#define JP 0x4300 
#define SHR 0x6100
//shift right ax
#define SHL 0x6200
//shift left ax
#define AND 0x7000
// ax and mem
#define OR  0x7100
#define XOR 0x7200
#endif
