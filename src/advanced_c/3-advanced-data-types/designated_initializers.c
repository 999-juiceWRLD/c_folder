#include <stdio.h>

int main() {

    int foo[6] = { [3]=1, [5]=2 };
    int bar[12] = { [1]=12, [4 ... 9]=8};
    int gee[] = { [1]=7, [6 ... 10]=8, [17]=345};

    for (int i = 0; i < 18; i++) {
        printf("%d ", gee[i], i);
    }

    return 0;
}
