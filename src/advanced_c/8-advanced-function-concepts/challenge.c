#include <stdio.h>
#include <stdarg.h>

int adding_numbers(int n_how_many, ...);

int main() {

    printf("Variadic functions:\n");
    printf("10 + 20 = %d\n", adding_numbers(2, 10, 20));
    printf("10 + 20 + 30 = %d\n", adding_numbers(3, 10, 20, 30));
    printf("10 + 20 + 30 + 40 = %d\n", adding_numbers(4, 10, 20, 30, 40));
    
    return 0;
}

int adding_numbers(int n_how_many, ...) {
    int sum = 0;
    va_list int_argument_pointer;
    va_start(int_argument_pointer, n_how_many);

    for (int i = 0; i < n_how_many; i++) {
        sum += va_arg(int_argument_pointer, int);
    }
    va_end(int_argument_pointer);

    return sum;
}
