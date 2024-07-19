#include <stdio.h>
#define PX printf("x is %d.\n", x);

int main() {

    int x = 42;
    PX;

    return 0;
}