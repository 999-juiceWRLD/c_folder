#include "stdio.h"

int main() {
    
    FILE *f;
    f = fopen("text.txt", "r");
    fclose(f);

    if (f == NULL) {
        printf("error, no such file.\n");
    }
}