#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vla.h"

int generate_random_number() {
    return rand() % RANGE + LOWER_BOUND;
}

void assign_nums(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int random_number = generate_random_number();
        *(arr + i) = random_number;
    }
}

int* generate_vla(int size) {
    int array[size];
    int *array_ptr = (int *) malloc(size * sizeof(int));
    if (array_ptr == NULL) {
        printf("An error has occured.\n");
        exit(EXIT_FAILURE);
    }
    assign_nums(array_ptr, size);
    return array_ptr;
}

void traverse_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int array_size(int *arr) {
    int size = 0;
    while (*arr != 0) {
        size++;
        arr++;
    }
    return size;
}

int main() {

    srand(SEED);

    int *ptr_1 = generate_vla(FIRST);
    int *ptr_2 = generate_vla(SECOND);
    int *ptr_3 = generate_vla(THIRD);

    traverse_array(ptr_1, FIRST);
    traverse_array(ptr_2, SECOND);
    traverse_array(ptr_3, THIRD);

    printf("FIRST array size: %d\n", array_size(ptr_1));
    printf("SECOND array size: %d\n", array_size(ptr_2));
    printf("THIRD array size: %d\n", array_size(ptr_3));

    free(ptr_1);
    free(ptr_2);
    free(ptr_3);

    return 0;
}


