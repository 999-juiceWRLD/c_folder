#include <stdio.h>

typedef union _student {
    char letterGrade;
    int roundedGrade;
    float exactGrade;
} student;

void traverse_union(student *union_ptr);

int main() {

    student variable1, variable2, *var1_ptr, *var2_ptr;
    var1_ptr = &variable1;
    var2_ptr = &variable2;

    var1_ptr->letterGrade = 'B';
    var1_ptr->roundedGrade = 87;
    var1_ptr->exactGrade = 86.50;
    
    traverse_union(var1_ptr);

    var2_ptr->letterGrade = 'A';
    printf("\nLetter: %c\n", var2_ptr->letterGrade);
    var2_ptr->roundedGrade = 100;
    printf("Rounded: %d\n", var2_ptr->roundedGrade);
    var2_ptr->exactGrade = 99.50;
    printf("Exact: %f\n", var2_ptr->exactGrade);

    return 0;
}

void traverse_union(student *union_ptr) {
    printf("Letter: %c\n", union_ptr->letterGrade);
    printf("Rounded: %d\n", union_ptr->roundedGrade);
    printf("Exact: %f\n", union_ptr->exactGrade);
}

