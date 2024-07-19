#include <stdio.h>
#include <complex.h>

int main() {

    double complex z1 = 1.0 + 2.0 * I;  // 1 + 2i
    double complex z2 = 3.0 - 4.0 * I;  // 3 - 4i

    double complex sum = z1 + z2;
    double complex product = z1 * z2;
    double complex quotient = z1 / z2;

    printf("z1:         %.2f + %.2fi\n", creal(z1), cimag(z1));
    printf("z2:         %.2f %.2fi\n", creal(z2), cimag(z2));
    printf("Sum:        %.2f + %.2fi\n", creal(sum), cimag(sum));
    printf("Product:    %.2f + %.2fi\n", creal(product), cimag(product));
    printf("Qutioent:   %.2f + %.2fi\n", creal(quotient), cimag(quotient));

    return 0;
}