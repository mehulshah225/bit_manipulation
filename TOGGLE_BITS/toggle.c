/* The code intents to toogle certain bits of a number (signed or unsigned) */
/* Author: Mehul Shah */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// toggle function for unsigned number
void toggleUnsigned(uint32_t* a, int toggle, int toggle2){
    *a ^= (1u << toggle) | (1u << toggle2);
    printf("Toggle value: %u\n", *a);
}   

// toggle function for signed number
void toggleSigned(int* a, int toggle, int toggle2){
    *a ^= (1 << toggle) | (1 << toggle2);
    printf("Toggle value: %d\n", *a);
}

int main(int argc, char* argv[]){
    
    uint32_t num;
    int x;
    int option, toggle1, toggle2;

    printf("Press option:\n1. Signed\n2. Unsigned\n");
    scanf("%d", &option);

    if(option != 1 && option!= 2){
        printf("Incorrect value");
	exit(1);
    }

    printf("Enter bits to be toggled (eg: 6 7): ");
    scanf("%d %d", &toggle1, & toggle2);
    
    if(toggle1 >= 32 || toggle2 >= 32){
        printf("Out of bounds");
	exit(1);
    }

    switch(option){
        case 1:
            printf("Enter signed number: ");
            scanf("%d", &x);
            toggleSigned(&x, toggle1, toggle2);
            break;
        case 2:
            printf("Enter unsigned number: ");
            scanf("%u", &num);
            toggleUnsigned(&num, toggle1, toggle2);
            break;
        default:
            printf("Invalid choice");
            break;
    }

    return 0;
}
