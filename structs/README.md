# Structs

Structs are collection of related members. When using structs in C, we can't assign a value to an array like this:

```c
struct some_structure {
  int number;
  char letter;
  char text[30];
};

int main() {
  
  struct some_structure s1;
  s1.text = "Some text";
  printf("My string: %s", s1.text);

  return 0;
}
```

## The arrow `->` for structure pointer

Instead of accessing the elements using `(*pointer).element`, we can use `pointer->element` using and element of a `struct` in C.

```c
#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    // Declare a struct variable
    struct Student student1;

    // Initialize the struct using the dot operator
    student1.id = 1;
    strcpy(student1.name, "John Doe");
    student1.gpa = 3.8;

    // Declare a pointer to a struct
    struct Student *ptrStudent;

    // Assign the address of the struct variable to the pointer
    ptrStudent = &student1;

    // Access struct members using the arrow operator (->)
    printf("Student ID: %d\n", ptrStudent->id);
    printf("Student Name: %s\n", ptrStudent->name);
    printf("Student GPA: %.2f\n", ptrStudent->gpa);

    return 0;
}
```

## Pointers to Structures

C allows for pointers to structures. Pointers to structures are easier to manipulate than structures themselves.

- In some older implementations, a structure cannot be passed as an argument to a function, but a pointer to a structure can. Even if you can pass a structure as an argument, passing a pointer is more efficient.

- Many data representations use structures containing pointers to other structures.

```c
struct STRUCT_NAME *PTR_NAME;
struct STRUCT_NAME STRUCT_VAR;

PTR_NAME = &STRUCT_VAR;
(*PTR_NAME).ELEMENT_NAME;
// or
PTR_NAME->ELEMENT_NAME;
```

## Structures Containing Pointers

### Character Arrays or Character Pointers?

We can use both, but should know what's happening here.

```c
struct names {
  char first[20];
  char last[20];
}

struct pnames {
  char *first;
  char *last;
}

struct names veep = { "Talia", "Summers" };
struct pnames treas = { "Brad", "Fallingjaw" };
printf("%s and %s\n", veep.first, treas.first);
```

- For the `names`:
  - The `struct names` has allocated total 40 bytes to hold the two names (20 for each, as a `char` is 1 byte)
  - The strings are allocated inside the struct

- For the `pnames`:
  - The strings are stored wherever the compiler stores string constants.
  - The struct itself holds total of 16 bytes (8 for each) in our system.
  - The `struct pnames` allocates no space to store strings. It can be used only with string that have had space allocated for them elsewhere (such as a string constants or strings in arrays).
  - Therefore the pointers in the `pnames` structure should be used only to manage strings that were created and allocated elsewhere in the program.
  - In `pnames`, there's no memory allocated for string arrays. To actually allocate memory for what `char *first` and `char *last` are pointing to, we have to use `malloc`

## Structures and Functions

After declaring a structure, how do we pass this structure as an argument to a function?

We should use a pointer to a structure as an argument.
  - It can take quite a bit of time to copy large structures as arguments as well as requiring whatever amount of memory to store the copy of the structure. 
  - Pointers to structures avoid the memory consumption and the copying time (only a copy of the pointer argument is made)


[Dynamic memory allocation of structs](https://www.programiz.com/c-programming/c-structures-pointers)
[C Dynamic Memory Allocation](https://www.programiz.com/c-programming/c-dynamic-memory-allocation)
[C Structure and Function](https://www.programiz.com/c-programming/c-structure-function)