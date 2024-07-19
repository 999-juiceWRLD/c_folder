#include <stdio.h>

void swap_by_address_value(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main() {
    int *f_ptr, *s_ptr;
    int a = 10, b = 8;
    f_ptr = &a, s_ptr = &b;

    printf("first: %p (%d), second: %p (%d)\n", f_ptr, *f_ptr, s_ptr, *s_ptr); // first way
    swap_by_address_value(f_ptr, s_ptr);
    printf("first: %p (%d), second: %p (%d)\n", f_ptr, *f_ptr, s_ptr, *s_ptr); // first way

    return 0;
}