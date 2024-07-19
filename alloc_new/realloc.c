#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HERO    4
#define VILLAIN 7

void traverse_memory(char *ptr, int char_len) {
    for (int i = 0; i < char_len; i++) {
        printf("%c", ptr[i]);
    }
    printf("\n");
}

int main() {
    
    char *str = NULL;
    str = (char*) malloc(HERO * sizeof(char));
    strcpy(str, "HERO");

    traverse_memory(str, HERO);

    str = (char*) realloc(str, VILLAIN * sizeof(char));
    strcpy(str, "VILLAIN");

    traverse_memory(str, VILLAIN);

    free(str);
    str = NULL;

    return 0;
}
