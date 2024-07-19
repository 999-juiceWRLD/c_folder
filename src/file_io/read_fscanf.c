#include <stdio.h>
#define MAX 60

/*
    in this file, I intentionally tried to get the first
    two elements rather than whole.
*/
int main() {

    FILE *f;
    char *file_name = "sample.txt";
    char first_string[MAX], second_string[MAX], third_string[MAX];
    int integer;

    f = fopen(file_name, "w+");
    if (f != NULL) {
        fputs("we are in 2024", f);
    }
    rewind(f);

    if (f != NULL) {
        
    }

    int number = fscanf(f, "%s %s %s %d", first_string, second_string, third_string, &integer);
    printf("Number: %d\n", number);
    printf("String: %s\n", first_string);
    printf("String: %s\n", second_string);
    printf("String: %s\n", third_string);
    printf("Integer: %d\n", integer);

    fclose(f);
    remove(file_name);
    return 0;
}