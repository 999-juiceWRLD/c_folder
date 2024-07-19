#define CHAR_MAX 60

// using `typedef`, we can use `Person p` instead of `struct _person p`

typedef struct _person {
    char name[CHAR_MAX];
    char surname[CHAR_MAX];
    char profession[CHAR_MAX];
    int age;
    int experience;
} Person;

typedef struct _complex {
    float *real;
    float *imaginary;
} Complex;

typedef struct _family {
    char name[20];
    int age;
    char father[20];
    char mother[20];
} Family;
