#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
*A union allows to store different data types in the same memory location.
*each member of the unions shares the same memory location.
*Also provides an example of a struct.
*This program provides examples of working with bits.
*/

typedef struct{
    uint8_t enable : 1;
    uint8_t ready : 1;
    uint8_t mode : 2; //This is 2 bits long
    uint8_t something_else : 2;
}RegBits;

typedef union{
    RegBits bits;
    uint8_t byte;
} HardwareRegisterA;

typedef union{
    struct{
        uint8_t byte1;
        uint8_t byte2;
        uint8_t byte3;
        uint8_t byte4;
    } bytes;
uint32_t word;
}HardwareRegisterB;

void print_bits(void *data, int size){
    uint8_t *bytes = data;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 8; j++){
            printf("%d",(bytes[i] >> j) & 1);
        }
    }
    printf("\n");
}

int main(){

printf("How to use unions \n");

HardwareRegisterA regA = {.byte = 0x01};
printf("regA: 0x%02X", regA.byte);
print_bits(&regA, sizeof(regA));

HardwareRegisterB regB = {.word = 0xAABBCCDD};

printf("regB: %X\n",regB.word);

regB.bytes.byte2 = 0;
printf("regB: %X\n", regB.word);

regA.bits.mode = 3;
 
    return EXIT_SUCCESS;
};
