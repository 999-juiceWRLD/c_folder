#include <stdio.h>

int main(void) {
    int i = 10;
    float j = 9.9;
    char k = 'k';

    void *void_pointer;

    void_pointer = &i;
    printf("The value of the pointer is: %d\n", (*(int *)void_pointer));

    void_pointer = &j;
    printf("The value of the pointer is: %.1f\n", (*(float *)void_pointer));

    void_pointer = &k;
    printf("The value of the pointer is: %c\n", (*(char *)void_pointer));

    return 0;
}