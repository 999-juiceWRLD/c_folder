#include <stdio.h>
#include <string.h>

int main() {
    char string[1000] = "Let's tokenize this string!";
    printf("%s\n", string);
    printf("Tokenizing...\n\n");
 
    char *token = strtok(string, " ");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    return 0;
}