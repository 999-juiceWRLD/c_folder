#include <stdio.h>
#ifdef __STDC_NO_COMPLEX__
    #define RES 0 // complex numbers are not supported
#else
    #define RES 1
#endif

int main() {

    printf("%s\n", RES ? "true" : "false");
    return 0;
}