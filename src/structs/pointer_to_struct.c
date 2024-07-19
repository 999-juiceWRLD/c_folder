#include <stdio.h>
#include <string.h>
#include "typedef.h"

int main() {

    Person person, *ptr;
    ptr = &person;

    strcpy(person.name, "kimi");
    strcpy(person.surname, "raikkonen");
    strcpy(person.profession, "f1 pilot");
    person.age = 44;
    person.experience = 24;
    
    printf("%s %s, %d.\n", person.name, person.surname, person.age);
    printf("%d years of experience - %s.\n", person.experience, person.profession);

    // printf("%s %s, %d.\n", ptr->name, ptr->surname, ptr->age);
    // arrows are standing for the code below. they are same.
    printf("%s %s, %d.\n", (*ptr).name, (*ptr).surname, (*ptr).age);
    printf("%d years of experience - %s.\n", ptr->experience, ptr->profession);

    return 0;
}
