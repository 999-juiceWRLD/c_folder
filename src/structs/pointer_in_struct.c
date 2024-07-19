#include <stdio.h>
#include "typedef.h"

int main() {
    Complex complex;
    float r = 3.2, i;
    complex.real = &r;
    complex.imaginary = &i;
    *complex.imaginary = -1;

    // printf("%p real & %p imaginary\n", complex.real, complex.imaginary); // shows address
    printf("%.2f real & %.2f imaginary\n", *complex.real, *complex.imaginary);
    return 0;
}
