#include <stdio.h>
#include <stdlib.h>
#include "fam.h"

/*
    you don't have to point your struct pointer to another struct variable.
    like flexible_array_member fam_struct, *fam_ptr;
    fam_ptr = &fam_struct;
*/ 

int main() {
    int arr_len = 9;
    flexible_array_member *fam_ptr = NULL;

    // Calculate the total size of the structure with the flexible array
    size_t struct_size = sizeof(flexible_array_member);
    size_t array_byte_size = arr_len * sizeof(int);
    fam_ptr = malloc(struct_size + array_byte_size);

    if (fam_ptr == NULL) {
        printf("Memory allocation failed.\n");
        fam_ptr = NULL;
        exit(0);
    }

    fam_ptr->character = 'c';
    fam_ptr->array_len = arr_len; // 5 but you can basically make it any integer. it's independent of flexible array member size
    fam_ptr->array[0] = 999;      // let's explicitly define the first element of the array for experiment
    for (size_t i = 1; i < fam_ptr->array_len; i++) {
        fam_ptr->array[i] = i * i;
    }

    traverse_flexible_array(fam_ptr);

    free(fam_ptr);
}

void traverse_flexible_array(flexible_array_member *ptr) {
    for (size_t i = 0; i < ptr->array_len; i++) {
        printf("%d\n", ptr->array[i]);
    }
}
