// This program is to use the concept of getter and setters using pointers. The value is stored in a file
// Author: Mehul Shah

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t SetValue(unsigned int* w, int* i, int* j, unsigned int* v) {
    if (*j <= 31 && *j >= *i && *i >= 0) {
        *w = *v;
	
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

uint32_t GetValue(unsigned int* w, int* i, int* j) {
    // Retrieve the value from a file
    FILE* file = fopen("value.txt", "r");
    if (file) {
        fscanf(file, "0x%X", w);
        fclose(file);
    }
    return *w;
}

int main(int argc, char* argv[]) {
    unsigned int w = 0; // Declare 'w' outside the if block

    if (argc == 4) {
        int j = atoi(argv[1]);
        int i = atoi(argv[2]);
        unsigned int v = (unsigned int)strtoul(argv[3], NULL, 0); // Parse the value as hexadecimal

        printf("Usage : %s <j> <i> <v>\n", argv[0]);
       	SetValue(&w, &i, &j, &v);
	printf("Value has been set\nRun the command: %s <j> <v> \nThis will print the value\n", argv[0]);

    } else if (argc == 3) {
        int j = atoi(argv[1]);
        int i = atoi(argv[2]);
	printf("Usage : %s <j> <i>\n", argv[0]);
        printf("Retrieved value = 0x%X\n", GetValue(&w, &j, &i));
    }
    else {
        printf("Usage : %s <j> <i> <v>\n", argv[0]);
	return 1;
    }

    return 0;
}

