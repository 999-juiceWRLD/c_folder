#include <stdio.h>

#define PI 3.14
#define CIRCLE_AREA(X) (PI * (X) * (X))

int main() {

    int radius = 4;
    int area = CIRCLE_AREA(radius);
    printf("The area of a circle where r=%d: %d\n", radius, area);

    return 0;
}