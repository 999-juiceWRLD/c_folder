#include <stdio.h>

#pragma GCC poison printf

int main() {

    printf("say hi\n");

    return 0;
}

/*
OUTPUT:

pragma_poison.c:7:5: error: attempt to use a poisoned identifier
    printf("say hi\n");
    ^
1 error generated.
*/