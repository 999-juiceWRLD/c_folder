#include <stdio.h>

int somedisplay();
void funct1(int);
void funct2(int);
typedef void FunctType(int); // practice

// also look for qsort sometime

int main() {

    int (*func_ptr)();
    func_ptr = somedisplay;
    printf("The address of this function is: %p\n", func_ptr);
    (*func_ptr)();

    FunctType *f = NULL;
    f = funct1;
    (*f)(100);
    f = funct2;
    (*f)(200);

    return 0;
}

int somedisplay() {
    printf("-- Displaying some text --\n");
    return 0;
}

void funct1(int testarg) {
    printf("funct1 got an argument of %d\n", testarg);
}

void funct2(int testarg) {
    printf("funct2 got an argument of %d\n", testarg);
}
