#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    // realloc

    // realloc function enables you to reuse or extend memory
    // that you previously allocated using malloc() or calloc().

    // expects two args: 
    // 1-) a pointer containing an address that was previously
    // returned by a call to malloc() or calloc().
    // 2-) the size in bytes of the new memory want to be allocated.

    // return void* pointer or NULL as malloc() and calloc().
    // realloc() preserves the contents of the original memory area.

    char *str;
    str = (char*) malloc(15* sizeof(char));
    strcpy(str, "jason");
    printf("String = %s Address = %p\n", str, str);

    if (!str) {
        free(str);
        str = NULL;
        exit(0);
    } else {
        // reallocating memory

        str = (char*) realloc(str, 25* sizeof(char));
        strcat(str, ".com");
        printf("String = %s Address = %p\n", str, str);

        free(str);
        str = NULL;
        exit(0);
    }
    return 0;
}