#include <stdio.h>

int main() {

    FILE *f;
    char ch;

    f = fopen("write.txt", "w+");
    // characters representing the ascii table
    for (ch = 33; ch <= 100; ch++) {
        fputc(ch, f);
    }
    fclose(f);
    return 0;
}