/* This program is to use to set a particular value within range [i,j] and update the new value */
/* Author: Mehul Shah */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t SetValue(unsigned int* w, int i, int j, unsigned int v) {
    // Condition to check if the bits to be set are within unsigned range
    if (j <= 31 && j >= i && i >= 0) {  
        int mask = 0;
        for(int k = i; k <= j; k++){
            mask |= (1<<k);
        }
        // Shifting v by i bits to be ORed with new value
        v <<= i;                     
        //Clear bits within range of w and set v bits in the given range
        *w = (mask & v) | *w;        

        // Store the value in a file
        FILE* file = fopen("value.txt", "w");
        if (file) {
            fprintf(file, "0x%X", *w);
            fclose(file);
        }
    } else {
        printf("Bit range is out of bounds\n");
    }
    return *w;
}

uint32_t GetValue(unsigned int* w, int i, int j) {
    // Retrieve the value from a file
    FILE* file = fopen("value.txt", "r");
    if (file) {
        fscanf(file, "0x%X", w);
        fclose(file);
    }
    return *w;
}

int main(int argc, char* argv[]) {
    unsigned int w = 10;    // The value which is to be modified

    if (argc == 4) {
        int j = atoi(argv[1]);
        int i = atoi(argv[2]);
        unsigned int v = (unsigned int)strtoul(argv[3], NULL, 0); // Parse the value as hexadecimal

        printf("Usage : %s <j> <i> <v>\n", argv[0]);

        if(j <=31 && j >= i && i >=0){
            printf("Value of w before modyfying: 0x%X\n", w);
            SetValue(&w, i, j, v);
            printf("New value has been set\nRun the command: %s <j> <v>\n", argv[0]);
        }
        else{
            if(i > j)
                printf("<i> parameter needs to be reduced");
            else
                printf("Out of bounds (32 bits only)");
        }
    } 
    else if (argc == 3) {
        int j = atoi(argv[1]);
        int i = atoi(argv[2]);
        printf("Usage : %s <j> <i>\n", argv[0]);
        printf("Retrieved value = 0x%X\n", GetValue(&w, j, i));
    }
    else {
        printf("Usage : %s <j> <i> <v>\n", argv[0]);
        return 1;
    }

    return 0;
}
