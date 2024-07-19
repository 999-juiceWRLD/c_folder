#include <stdio.h>

int main() {

    char letter;
    char *p_letter = NULL;
    char **pp_letter = NULL;

    letter = 'a';
    p_letter = &letter;
    pp_letter = &p_letter;

    printf("char:                                                 %c\n", letter);
    printf("pointer to char:                         %p, %c\n", p_letter, *p_letter);
    printf("pointer to pointer to char: %p, %p, %c\n", pp_letter, *pp_letter, **pp_letter);

    return 0;
}