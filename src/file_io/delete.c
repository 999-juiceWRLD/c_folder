#include "stdio.h"
#include <unistd.h> // used for sleep()

int main() {

    FILE *f;
    f = fopen("to_be_deleted.txt", "w");
    sleep(3);
    remove("to_be_deleted.txt");
    printf("The file is deleted.\n");
    
    return 0;
}