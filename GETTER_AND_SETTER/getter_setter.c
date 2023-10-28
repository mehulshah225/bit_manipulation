// This program is to use the concept of getter and setters using pointers. The value is stored in a file
// Author: Mehul Shah

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t SetValue(unsigned int* w, int* i, int* j, unsigned int* v) {
    if (*j <= 31 && *j >= *i && *i >= 0) {
        *w = *v;
        printf("Value has been set\n Now again run the command to get the value\n");

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

        SetValue(&w, &i, &j, &v);
    } else if (argc == 3) {
        int j = atoi(argv[1]);
        int i = atoi(argv[2]);
        printf("Retrieved value = 0x%X\n", GetValue(&w, &j, &i));
    } else if (argc > 4) {
        printf("Too many arguments\n");
    } else {
        printf("Not enough arguments\n");
    }

    return 0;
}

