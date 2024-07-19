#include <stdio.h>

#define PI 3.14
#define CIRCUMFERENCE(PI, r) (PI * r * 2)
#define AREA(length, width) (length * width)


int main() {
    int radius = 5;
    float circ = CIRCUMFERENCE(PI, radius);
    printf("The circumference of r=5 is: %.2f\n", circ);

    int l = 15;
    int w = 8;
    
    
    float area = AREA(l, w);
    printf("The area of the rectangle is: %.2f\n", area);
    return 0;
}