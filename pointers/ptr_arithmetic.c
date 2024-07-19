#include <stdio.h>

int array_sum(int *array, const int n) {
    int sum = 0, *ptr;
    int *const array_end = array + n; // address of the array + size
    printf("pointer address: %p, value: %d\n", array_end, *array_end);
    for (ptr = array; ptr < array_end; ++ptr) {
        printf("digit: %d, address: %p\n", *ptr, ptr);
        sum += *ptr;
    }
    ptr++;
    printf("%p -> %p\n", array_end, ptr);

    return sum;
}

int main(void) {

    int arr [4] = {0, 1, 2, 3};
    int *const arr_ptr = arr + (sizeof(arr) / sizeof(int));
    printf("%d?\n", array_sum(arr, 4));

    return 0;
}