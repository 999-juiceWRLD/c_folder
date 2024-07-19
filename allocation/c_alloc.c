#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // calloc

    // it allocates memory as a number of elements
    // of a given size

    // it initializes the memory that is allocated
    // so that all bytes are zero

    // arguments: number of data items, size of each item

    int *pNumber = (int*) calloc(75, sizeof(int));
    if (!pNumber) {
        free(pNumber);
        pNumber = NULL;
        exit(0);
    } else {
        int i = 0;
        printf("First element in the calloc is %d\n", *(pNumber + i));

        i++;
        printf("Second element in the calloc is %d\n", *(pNumber + i));
        
        i += 5;
        printf("Third element in the calloc is %d\n", *(pNumber + i));
    
        free(pNumber);
        pNumber = NULL;
        exit(0);
    }

    return 0;
}