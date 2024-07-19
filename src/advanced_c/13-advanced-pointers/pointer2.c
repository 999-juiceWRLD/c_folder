#include <stdio.h>
#include <stdlib.h>

void change_value(int **ptr) {
    int a = 5;
    *ptr = &a;
}

int main() {

    // int **ptr = NULL;
    
    int **ptr = (int **) malloc(sizeof(int *));
    *ptr = (int *) malloc(sizeof(int));
    **ptr = 10;

    printf("%d\n", **ptr);
    change_value(ptr);
    printf("%d\n", **ptr);

    free(ptr);
    free(*ptr);

    return 0;
}