#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 12
#define SEED 42
#ifndef RANGE
    #define LOWER_BOUND 0
    #define UPPER_BOUND 100
    #define RANGE UPPER_BOUND - LOWER_BOUND + 1
#endif

int generate_unsecure_random() {
    return rand() % RANGE + LOWER_BOUND;
}

void traverse_calloc(float *float_pointer) {
    for (int i=0; i<SIZE; i++) {
        printf("%.0f ", float_pointer[i]);
    }
    printf("\n");
}

void insert_to_calloc(float *float_pointer) {
    for (int i=0; i<SIZE; i++) {
        int random_number = generate_unsecure_random();
        float_pointer[i] = random_number;
    }
}

int main() {

    srand(SEED);

    float *ptr = (float*) calloc(SIZE, sizeof(float));

    printf("initial calloc array traversal\n");

    traverse_calloc(ptr);
    insert_to_calloc(ptr);
    
    printf("generated randoms are inserted to calloc. traversing again:\n");

    traverse_calloc(ptr);
    
    return 0;
}