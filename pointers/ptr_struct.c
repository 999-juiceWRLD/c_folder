#include <stdio.h>
#include <string.h>

struct Employee {
    char name [25];
    int age;
    char job [20];
} emp;   

int main(void) {

    strcpy(emp.name, "John");
    emp.age = 28;
    strcpy(emp.job, "Accountant");

    printf("Name: %s\n", emp.name);
    printf("Job: %s\n", emp.job);
    
    struct Employee *ptr_emp;
    ptr_emp = &emp;

    printf("Employee age: %d\n", (*ptr_emp).age);

    // (*x).y equals to x -> y - more convenient
    printf("Employe age again: %d\n", ptr_emp -> age);

    ptr_emp -> age = 11;
    printf("Man, this guy is %i, he's underage!\n", ptr_emp -> age);

    return 0;
}