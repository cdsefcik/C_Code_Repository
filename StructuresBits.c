#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
 *This shows how to work with bits using structures. 
 *Traverses the bits and prints them out.
 * 
 */

typedef struct ledStatus{
    uint8_t led_1;
    uint8_t led_2;
    uint8_t led_3; //8 Bits long

}LedStatus;

typedef struct LedStatusBitfields{

    uint8_t led_1 : 1;
    uint8_t led_2 : 1;
    uint8_t led_3 : 1; //1 Bit long

}LedStatusBitfields;

void print_bits(uint8_t *data, int size){
    for(int i = 0; i < size; i++){
        uint8_t byte = data[i];
        for(int j = 0; j < 8; j++){
            printf("%d",(byte >> j) & 1);
        }
    }
}

int main(){

LedStatusBitfields status = {
.led_1 = 1,
.led_2 = 1,
.led_3 = 1,
};

print_bits((uint8_t *) &status, sizeof(status));

    return EXIT_SUCCESS;
};
