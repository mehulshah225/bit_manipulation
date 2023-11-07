/* C code to reverse bits in a byte */
/* Author: Mehul Shah */

#include <stdio.h>
#include <stdint.h>


// c function to reverse bits in a byte
void reverseBitsInByte(uint8_t num) {
    uint8_t temp = 0;
    for(int i = 0; i < sizeof(num)*8; i++) {
        temp = (temp << 1) | (num & 1);	   //Add 1 if true and left shift by 1
        num >>= 1;
    }
    printf("reverse: 0x%X\n", temp);
}

int main(void) {
    uint8_t num = 0xAA;
    reverseBitsInByte(num);
    return 0;
}
