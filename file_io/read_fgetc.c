#include <stdio.h>

int main() {

    FILE *file;
    char character;
    char *file_name = "read_this.txt";
    file = fopen(file_name, "r");
    int line_number = 0;

    if (file == NULL) {
        perror("Change file name");
    } else if (file != NULL) {
        do {
            character = fgetc(file);
            if (character == '\n') {
                line_number++;
            }
            if (feof(file)) {
                line_number++;
                printf("\n");
                break;
            }
            printf("%c", character);
        } while (character != EOF);
        fclose(file);
    }
    printf("number of lines is: %d\n", line_number);
    return 0;
}