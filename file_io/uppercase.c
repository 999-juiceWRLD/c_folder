#include <stdio.h>
#include <ctype.h>
#define READ 1

/*
    write a program that converts all characters of a file to uppercase and write
    the results out to a temporary file. Then rename the temporary. then rename
    the temporary file to the original filename and remove the temporary filename.

    note: you can convert a character to upper case by subtracting 32 from it.
*/

int main() {

    FILE *fr, *fw; // fr: file read, fw: file write
    char *file_read = "uppercase.txt";
    char *file_write = "uppercase_temp.txt";
    char character;
    char uppercase;
    fr = fopen(file_read, "r");
    fw = fopen(file_write, "w");

    if (fr == NULL) {
        perror("Change file name");
    }

    while ((character = fgetc(fr)) != EOF) {
        if (islower(character)) {
            character = toupper(character);
        }
        fputc(character, fw);
    }

    rewind(fr);
    rewind(fw);

    fclose(fr);
    fclose(fw);

    remove(file_read);
    rename(file_write, file_read);
    return 0;
}