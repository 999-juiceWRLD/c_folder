#include <stdio.h>
#include <string.h>

#define CHAR_MAX 60

// structs are collection of related members

struct User {
    char name[CHAR_MAX];
    char job[CHAR_MAX];
    int age;
};

int main() {

    struct User user1 = { "hero", "senior scientist", 28 };
    
    struct User user2;
    strcpy(user2.name, "alisa");
    strcpy(user2.job, "engineer");
    user2.age = 29;

    return 0;
}