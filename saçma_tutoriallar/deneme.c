#include <stdio.h>
// #include </Library/Frameworks/Python.framework/Versions/3.10/include/python3.10/Python.h>


// python interpreter path: 
// /usr/local/bin/python3

int main() {
    char _text [50] = "I'm in love with Lorentz transformations!";
    char (*text_p)[50] = &_text;

    char first_letter = (*text_p)[0];
    printf("The first_letter was: %c\n", first_letter);

    first_letter = 'p';
    printf("Now, the first_letter is: %c\n\n", first_letter);


    char *second_letter_ptr = &(*text_p)[1];
    printf("The second_letter pointer value was: %c\n", *second_letter_ptr);
    
    *second_letter_ptr = 'q';
    printf("Now, second_letter pointer value is: %c\n\n", *second_letter_ptr);

    // =============================================================
    
    FILE *file_pointer = fopen("whats_my_name.txt", "w");
    char question[23] = "My name is Heisenberg.";

    fputs(question, file_pointer);

    // =============================================================

    FILE *second_file = fopen("second_serious_try.txt", "w");
    char hello [20] = "Hello World";

    const char *ptr;
    ptr = &hello[0];
    fputs(ptr, second_file);

    return 0;
}
