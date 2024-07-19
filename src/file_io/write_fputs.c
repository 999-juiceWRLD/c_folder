#include <stdio.h>

int main() {

    FILE *f;

    f = fopen("write.txt", "w+");
    fputs("This is a simple text for this file.", f);
    fputs("lol", f);

    return 0;
}