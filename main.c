/*
 * =============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  main module
 *
 *        Version:  1.0
 *        Created:  06/15/2015 06:25:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ahmed Abd-El Mawgood (oddcoder), Ahmedsoliman0x666@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "sio.h"
#include "opcodedef.h"
#define MEMMAX  65536
void greeting ();
int getcode( uint16_t *memarray, int max); 
int main(){
    uint16_t *mem; // mem is memory
    if((mem= (uint16_t*) malloc( sizeof(uint16_t) * MEMMAX)) == NULL){
        puts("Error allocating memory.\n press enter to continue...");
        getchar();
        exit(1);
    }
    uint16_t ax,ex,ip;
    //ax is accumulator
    //ex is extended regester
    //ip is instruction pointer
    for (ip=MEMMAX-1;ip>=0;ip--) mem[ip]=0;
    greeting();
    if (getcode (mem, MEMMAX) != 0)exit(1);
    //decoding routines
    puts("+------------------------+");
    puts("| program excution starts|");
    puts("+------------------------+");
    ip=0;
    ax=0;
    ex=0;
    while(mem[ip] != HALT ){
        switch(mem[ip]){
            case READ:
                //WORKS
                ip++;
                char opcode[5];
                if(get_s(opcode , 4)==-1 || mem[ip] >= MEMMAX){
                    puts("Fatal Error: Memory overflow ");
                    return 1;
                }
                mem[mem[ip]] = strtol(opcode,NULL,16);
                break;

            case READAX:
                //works
                ip++;
                ax  = mem[ip];
                break;

            case WRITE:
                //WORKS
                ip++;
                printf("%04x\n",mem[mem[ip]]);
                break;

            case LOAD:
                //work
                ip++;
                ax = mem[mem[ip]];
                break;
            case STOR:
                //works
                ip++;
                mem[mem[ip]] = ax;
                break;
            case STORE:
                //work
                ip++;
                mem[mem[ip]] = ex;
                break;
            case ADDM:
                //work
                ip++;
                ax += mem[mem[ip]];
                break;
            case ADD:
                //work
                ip++;
                ax  += mem[ip];
                break;
            case SUBM:
                ip++;
                ax -= mem[mem[ip]];
                break;
            case SUB:
                ip++;
                ax += mem[ip];
                break;
            case DIVM:
                ip++;
                ax = ax/mem[mem[ip]];
                ex = ax -  mem[mem[ip]]*ax;
                break;
            case DIV:
                ip++;
                ax = ax/ mem[ip];
                ex = ax - mem[ip]*ax;
                break;
            case MULM:{
                ip++;
                int temp = ax*mem[mem[ip]];
                ax = temp & 0xFFFF;
                ex = temp & 0xFFFF0000;
                break;}
            case MUL:{
                ip++;
                int temp = ax*mem[ip];
                ax = temp & 0xFFFF;
                ex = temp & 0xFFFF0000;
                break;}
            case JMP:
                //works
                ip++;
                ip = mem[ip]*2-1;
                break;
            case  JN:
                //works
                ip++;
                if(ax <0) ip = mem[ip]*2-1;
                break;
            case  JZ:
                //works
                ip++;
                if(ax ==0) ip = mem[ip]*2-1;
                break;
            case JP:
                //works
                ip++;
                if(ax >0) ip = mem[ip]*2-1;
                break;
            case SHR:
                ip++;
                ax = ax >> mem[mem[ip]];
                break;
            case SHL:
                ip++;
                ax = ax << mem[mem[ip]];
                break;
            case AND:
                ip++;
                ax = ax & mem[mem[ip]];
                break;
            case OR:
                ip++;
                ax = ax | mem[mem[ip]];
                break;
            case XOR:
                ip++;
                ax = ax ^mem[mem[ip]];
                break;

        };
        ip++;
    }
    //halt routines
    puts("Simpletron Halts!");


    char a = 'a';
    do{
        printf("Dump registers ? (y or n)");
        a = getchar();
        getchar(); // for the \n after the character
    }while(a != 'y' && a != 'n' && a != 'Y' && a != 'N');
    if (a == 'y' || a == 'Y'){
    puts("register dump");
    printf("ax\t%04x\nex\t%04x\n",ax,ex);
    }
    do{
        printf("Dump memory? (y or n)");
        a = getchar();
        getchar(); // for the \n after the char
    }while(a != 'y' && a != 'n'&& a != 'Y' && a != 'N');
    if (a == 'y' || a == 'Y'){

    puts("\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\tA\tB\tC\tD\tE\tF\n");
    for(ip=0;ip<0xFFF;ip++){
        printf("%03x\t",ip);
        for(ex=0;ex<=0xF;ex++) printf("%04x\t",mem[ip*10+ex]);
        puts("");
    }
    printf("FFF\t");
    for(ex=0;ex<0xF;ex++) printf("%04x\t",mem[0xFFF0+ex]);
    puts("");
    }
    return 0;    
}


int getcode( uint16_t *memarray, int max){
    char opcode[5];
    if(get_s(opcode , 4)==-1){
        puts("Fatal Error: Unexpected expression length ");
        return 1;
    } 
    int16_t ir,ip=0;
    ir = strtol(opcode,NULL,16);
    while(ir !=-1) {
        if(ip >= max) {
            puts("Fatal Error: memory overflow");
            return 1;
        }
        memarray[ip] = ir;
        ip++;
        if(get_s(opcode , 4)==-1){
            puts("Fatal Error: Unexpected expression length ");
            return 1;
        }
        ir = strtol(opcode,NULL,16);
    }
    return 0;
}
void greeting ()
{
    puts("*** Welcome to Simpletron Simulator! ***");
    puts("*** Created by ahemed Mohamed Abd El Mawgood! ***");
    puts("*** ahmedsoliman0x666 (at) gmail.com ***");
}
