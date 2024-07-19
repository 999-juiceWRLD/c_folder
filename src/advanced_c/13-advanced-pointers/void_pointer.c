#include <stdio.h>

int main() {

    int i = 10;
    float f = 2.34;
    char ch = 'g';

    void *vptr = NULL;
    vptr = &i;

    printf("Value of i = %d\n", *(int *)vptr); // cast is only on line 12, it's still a void pointer

    vptr = &f;
    printf("Value of f = %.2f\n", *(float *)vptr);

    vptr = &ch;
    printf("Value of ch = %c\n", *(char *)vptr);

    ////////////////////////////////////

    void *pvData = NULL;    // void pointer
    int *iData = NULL;      // integer pointer
    char *cData = NULL;     // character pointer
    float *fData = NULL;    // float pointer

    // size of void pointer
    printf("\nsize of void pointer = %lu\n", sizeof(pvData));

    // size of void pointer
    printf("size of integer pointer = %lu\n", sizeof(iData));

    // size of void pointer
    printf("size of character pointer = %lu\n", sizeof(cData));

    // size of void pointer
    printf("size of float pointer = %lu\n", sizeof(fData));

    return 0;
}