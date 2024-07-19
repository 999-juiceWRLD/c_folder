#include <stdio.h>

int main() {

    FILE *f;
    char *file_name = "write.txt";
    f = fopen(file_name, "w");
    if (f != NULL) {
        fprintf(f, "%s %s %s %s %d", "My", "lucky", "number", "is", 123);
    }
    fclose(f);
    return 0;
}