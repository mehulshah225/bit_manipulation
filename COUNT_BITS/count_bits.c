/* C code to count and display number of bits of an array */
/* Author: Mehul Shah */

#include <stdio.h>
#include <stdint.h>

// C program to count number of bits for individual element in an array
void count_bits(int* arr, int size){
        for(int i = 0; i < size; i++){
                int count = 0;
                int temp = *(arr+i);
                while(temp){
                        if(temp & 1){
                            count++;
                        }
                        temp >>= 1;
                }
                printf("arr[%d] has %d on bits\n", i, count);
        }
}

int main(void){
        int arr[] = {0xA, 0xFE, 1234, 4522};

        int size = sizeof(arr)/sizeof(arr[0]);

        count_bits(arr, size);

        return 0;
}

