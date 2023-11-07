/* C code to mask given no of bits and display result */
/* Author: Mehul Shah */

#include <stdio.h>
#include <stdint.h>


// c function to mask given no of bits
void maskBits(uint8_t num, int mask){
    uint8_t result = 0;
    
    for(int i = 0; i < mask; i++){
    	 result = (result << 1) | 1;	// Create mask of n bits
    }
   	result = result & num;    // And it with number
    printf("new number: 0x%X\n", result);
}

int main(void){

        uint8_t num = 0xAA;
        int mask = 6;

        maskBits(num, mask);

        return 0;
}
