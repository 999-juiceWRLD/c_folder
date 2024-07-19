#include <stdio.h>

#define UK      1
#define France  2
#define Germany 3
#define Country 12

int main() {
    #if Country == US || Country == UK
        #define Greeting "Hello."
    #elif Country == France
        #define Greeting "Bonjour."
    #elif Country == Germany
        #define Greeting "Guten tag."
    #else
        #define Greeting "- it's something else."
    #endif

    printf("Greetings is %s\n", Greeting);

    return 0;
}