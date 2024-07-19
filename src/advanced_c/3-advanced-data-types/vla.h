#ifndef VLA_H

#define SEED 42
#ifndef RANGE
    #define LOWER_BOUND 0
    #define UPPER_BOUND 100
    #define RANGE UPPER_BOUND - LOWER_BOUND + 1
#endif
#define FIRST   9
#define SECOND  4
#define THIRD   14

int generate_random_number();
void assign_nums(int *array, int size);
int* generate_vla(int size);
void traverse_array(int *array, int size);
int array_size(int *array);

#endif // VLA_H
