#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // dynamic memory reserves data in the heap

    // address of the first byte is returned, so 
    // a pointer is the place to put it.
    
    int *malloc_ptr = (int*) malloc(5* sizeof(int));

    // to deal with memory allocation problem
    if (!malloc_ptr) {
        printf("Memory allocation problem. Program will be terminated.\n");
        free(malloc_ptr);
        malloc_ptr = NULL; // after free(), no memory allocated for it
        exit(0);
    } else {
        printf("\nPointer to the memory is succesfully returned.\n");
        int i = 0;
        printf("First element: %d address: %p\n", *(malloc_ptr + i), (malloc_ptr + i));
        
        i++;
        printf("Second element: %d address: %p\n\n", *(malloc_ptr + i), (malloc_ptr + i));

        free(malloc_ptr);
        malloc_ptr = NULL; // after free(), no memory allocated for it
        exit(0);       
    }
    return 0;
}