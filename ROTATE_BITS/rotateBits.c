/* C code to rotate bits of a number, given the position */
/* Author: Mehul Shah */

#include <stdio.h>
#include <stdint.h>

// Function to rotate bits to right by position
void rotateBits(uint8_t num, int pos){
	num = (num >> pos) | (num << (8 - pos));
	printf("After rotation: %u\n", num);
}

int main(void){
	uint8_t number = 23;
	int position = 3;

	rotateBits(number, position);

	return 0;
}
