#include <stdio.h>

union car {
    int year;
    double km;
};

int main() {

    union car car1, *car_ptr;

    car_ptr = &car1;

    car_ptr->year = 2024;

    printf("%d\n", car_ptr->year);

    return 0;
}