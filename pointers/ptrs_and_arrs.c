#include <stdio.h>

int main(void) {

    int array[5] = {1, 2, 3, 4, 5};
    int *arr_ptr;
    arr_ptr = &array[0];

    printf("\nThe size of the array is: %lu\n\n", sizeof(array) / sizeof(int));


    for (int i = 0; i < (sizeof(array) / sizeof(int)); i++) {
        printf("Pointer value is: %d\n", *(array + i));
    }

    printf("==============================\n");

    double new_array[8] = {0.0, 0.0, 1.4, 2.3, 5.567};
    int index = 0;

    printf("%d. element -> %.1f\n", index, *(new_array + index));

    index += 2;
    printf("%d. element -> %.1f\n", index, *(new_array + index));
    
    index += 1;
    printf("%d. element -> %.1f\n", index, *(new_array + index));

    printf("==============================\n");

    int another_array[5] = {10, 9, 8, 7, 6};
    int *last_pointer = &another_array[0];
    int last_idx = 0;

    printf("%d\n", *(last_pointer + last_idx));
    printf("2 elements later: %d\n", *(last_pointer + 2));

    last_pointer++;
    printf("1 element later from the first pointer: %d\n", *last_pointer);
    return 0;
}