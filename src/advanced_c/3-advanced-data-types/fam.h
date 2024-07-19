#ifndef FLEXIBLE_ARRAY_MEMBER
typedef struct _flexible_array_member {
    char character;
    int array_len;
    int array[];
} flexible_array_member;

void traverse_flexible_array(flexible_array_member *fam_ptr);

#endif // FLEXIBLE_ARRAY_MEMBER