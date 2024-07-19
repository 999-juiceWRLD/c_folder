#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "typedef.h"

bool are_siblings(Family *pmember1, Family *pmember2) {
    if (strcmp(pmember1->mother, pmember2->mother) == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {

    Family son = { "kid", 11, "jason", "jane" };
    Family daughter = { "molly", 16, "jason", "jane" };
    Family someone_else = { "random", 8, "dad", "mom" };

    Family *son_ptr, *daughter_ptr, *someone_else_ptr;
    son_ptr = &son;
    daughter_ptr = &daughter;
    someone_else_ptr = &someone_else;

    bool are_sib = are_siblings(son_ptr, daughter_ptr);
    printf("Are son and daughter siblings? -> %d\n", are_sib);
    printf("Are son and daughter siblings? -> %s\n", are_sib ? "true" : "false");

    bool are_sib_else = are_siblings(someone_else_ptr, daughter_ptr);
    printf("Are son and daughter siblings? -> %d\n", are_sib_else);
    printf("Are son and daughter siblings? -> %s\n", are_sib_else ? "true" : "false");
    return 0;
}
