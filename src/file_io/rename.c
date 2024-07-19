#include "stdio.h"
#include <unistd.h> // used for sleep()

int main() {

    FILE *file;

    file = fopen("new_file.txt", "w");
    fclose(file);

    sleep(3); // sleep for 3 seconds

    int res = rename("new_file.txt", "renamed_file.txt");
    if (res == 0) {
        printf("Name change was successful. %d \n", res);
    } else {
        printf("Name change was not successful. %d\n", res);
    }
    return 0;
}