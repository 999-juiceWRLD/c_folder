#include <stdio.h>

int main() {

    FILE *file;
    char *file_name = "read_this.txt";
    char char_read;
    file = fopen(file_name, "r");

    // if (file != NULL) {
    // add indentation if you're going to enable the if conditional.
    do {
        char_read = fgetc(file);
        if (feof(file)) {
            break;
        }
        printf("%c", char_read);
    } while (char_read != EOF);
    // }

    return 0;
}