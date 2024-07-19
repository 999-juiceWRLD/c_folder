#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../structs/typedef.h"

#define MALLOC_ELEMENT_NUMBER 5
#define SEED 42

int main() {

    srand(SEED);
    int lower_bound = 0, higher_bound = 100;
    int range = higher_bound - lower_bound + 1;
    
    Person p = { "john", "doe", "aerospace engineer", 24, 2};
    printf("%s %s is an %s, age: %d exp: %d yrs\n", p.name, p.surname, p.profession, p.age, p.experience);

    int *int_ptr = (int*) malloc(5*sizeof(int));
    if (!int_ptr) {
        printf("There's an error with int_ptr\n");
        free(int_ptr);
        int_ptr = NULL;
        exit(0);
    } else {
        for (int i = 0; i < MALLOC_ELEMENT_NUMBER; i++) {
            int random_number = rand() % range + lower_bound;
            // int_ptr[i] = random_number; // it's the same with the codeline below
            *(int_ptr + i) = random_number;
        }

        for (int i = 0; i < MALLOC_ELEMENT_NUMBER; i++) {
            printf("%d\n", *(int_ptr + i));
        }

        printf("*int_ptr has dynamically allocated. Now terminating.\n");
        free(int_ptr);
        int_ptr = NULL;
        exit(0);
    }
    return 0;
}
