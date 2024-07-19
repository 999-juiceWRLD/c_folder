#include "stdio.h"

int main() {

    FILE *f;
    f = fopen("created_file.txt", "w");
    fclose(f);

    return 0;
}