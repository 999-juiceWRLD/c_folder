#include <stdio.h>
#include "typedef.h"

// Person p1 = { "name", "surname", "job", 999, 999 };

int main() {

    Person writer = { "knut", "hamsun", "writer", 45, 22 };
    Person scientist = { "werner", "heisenberg", "physicist", 39, 15 };
    
    printf("%s %s, %d.\n", writer.name, writer.surname, writer.age);
    printf("%d years of experience - %s.\n", writer.experience, writer.profession);

    char text[100];
    scanf("%s", text);
    printf("entry: %s\n", text);

    return 0;
}