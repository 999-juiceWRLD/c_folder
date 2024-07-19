#include <stdio.h>

void swap_numbers(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;

    printf("x is %d\ny is %d\n", *x, *y);
};

void print_to_file() {

    FILE *file_ptr;
    file_ptr = fopen("new_file.txt", "w");
    
    const char *str;
    char hello[150] = "It actually doesn't matter if the char array is const or not.";
    str = &hello[0];

    fputs(str, file_ptr);

    // ===========================================

    FILE *second_file_ptr;
    second_file_ptr = fopen("deli_mi_ne.txt", "w");

    const char *str2;
    const char wuzzupp[23] = "I feel amazing somehow!";
    str2 = &wuzzupp[0];

    fputs(str2, second_file_ptr);
};

int main(void) {

    int first_number = 10;
    int second_number = 15;

    int *f = &first_number;
    int *s = &second_number;

    swap_numbers(f, s);
    print_to_file();

    return 0;
}