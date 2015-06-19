# smlemul
simpletron emulator is a very simple processor emulator

simpletron is a simple processor emulator that is 16 bit with 64k memory

all intructions are found in opcodedef.h with there opcode and tiny explaination

the implementation is found in main.c


I haven't tested the smlemul heavily just few tiny progs to make sure everything is fine


this is simple program that sum up all numbers till zero is entered


line inst  arg

0000 READ  0050

0001 LOAD  0050

0002 JZ    0006

0003 ADDM  0051

0004 STORE 0051

0005 JMP   0000

0006 WRITE 0051

0007 HALT

FFFF

opcode


1000

0050

2100

0050

4200

0006

3000

0051

2200

0051

4000

0000

2000

0051

0100

FFFF


note that the smlemul only accepts the opcode 16 bit at a line
also you should know that every program should end with the HALT command and in order to start excuting code you should enter ffff or FFFF
