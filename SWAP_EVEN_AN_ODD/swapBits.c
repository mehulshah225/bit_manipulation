/* This code intends to swap even and odd bits in a 8-bit unsigned number*/
/* Author: Mehul Shah */

#include <stdio.h>
#include <stdint.h>
#define EVEN 0x55
#define ODD 0xAA

// Function to swap the bits
void swapBits(uint8_t* number){
	*number = ((*number & EVEN) << 1) | ((*number & ODD) >> 1);

	printf("Swapped : %u\n", *number);
}

int main(int argc, char* argv[]){

	uint8_t num;
	printf("Enter number: ");
	scanf("%hhu", &num);

	swapBits(&num);

	return 0;
}
