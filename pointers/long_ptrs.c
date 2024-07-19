#include <stdio.h>

void swap(int *x, int *y, char *s) {
    int temp = *x;
    *x = *y;
    *y = temp;
    char *endArr = s + 5;
    do {
        printf("%c", *s);
        s++;
    } while (s < endArr);
    
    printf("\n%d----%d\n", *x, *y);
}

int main(void) {

    long multiple_arr [] = {15L, 25L, 35L, 45L};
    long *p = multiple_arr;

    printf("\n");
    for (int i = 0; i < (sizeof(multiple_arr) / sizeof(long)); i++) {
        printf("address %d (&multiple_arr[%d]): %p  *(p + %d) value: %ld\n", 
        i, i, (p + i), i, *(p + i));
        
    }
    printf("\nType long occupies %d bytes\n", (int)sizeof(long));
    
    //////////////////////////////////

    int a = 10, b = 15;
    swap(&a, &b, "selam");

    return 0;
}