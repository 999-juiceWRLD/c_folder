#include <stdio.h>

#define MAX 11

int main() {

    FILE *f;
    char string[MAX];

    f = fopen("read_this.txt", "r");
    if (f == NULL) {
        perror("Not found");
    }
    
    if (fgets(string, MAX, f) != NULL) {
        printf("%s", string);
    }

    printf("\nReading is done\n");
    fclose(f);

    return 0;
}