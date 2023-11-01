/* C code to find single element in an array using bitwise operation */
/* Author: Mehul Shah */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to find out the non-repeating element
void bitwiseSearch(int arr[], int size){

    int result = 0;
    
    for(int i = 0; i < size; i++){
        // XOR all the result
	result ^= arr[i];
    }

    printf("Single non-repeating element: %d\n", result);
}

int main(void){

    int arr[] = {2, 3, 1, 2, 4, 4, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    bitwiseSearch(arr, size);

    return 0;
}
