# Type Qualfiers

Type qualfiers can be used in front of variables to give the compiler more information about the intended use of the variable.
- helps with optimization

These properties are declared with the keywords `const` and `volatite`, which create qualified types. The C99 standard added a third qualifier, `restrict` designated to facilitate compiler optimizations.

Type qualifiers are idempotent (added in C99) which means that you can use the same qualifier more than once in a declaration, and the superfluous ones are ignored.

## `const`

The compiler allows you to associate the `const` qualifier with variables whose values will not be changed by the program.
- you can tell the compiler that the specified variables have a constant value throughout the program's execution.
- if you try to assign a value to a `const` variable after initializing it, the compiler might issue an error message, although it is not required to do so.

One of the motivations for the `const` attribute in the language is that it allows the compiler to place your `const` variables into read-only memory.

## `const` vs. `#define`

`#define` is preprocessor directive while `const` is a keyword. `const` variables are actual variables like any other normal variable. We can pass them around, typecast them and any other thing that can be done with a normal variable.

## `volatile`

The `volatile` type qualifier tells the compiler explicitly that the specified variable will change its value.

It is provided so that a program can tell the compiler to suppress various kinds of optimizations.
- prevents the compiler from optimizing away seemingly redunddant
- prevents the compile from repeated examination of a variable without its value seemingly changing

Essentially, prevents the compiler from *caching* variables.

The reason for having this type qualifier is mainly because of the problems that are encountered in real-time or embedded systems programming
- programs that have a lot of threading
- programs where resources are scarce

### Use Cases

- A variable should be declared volatile whenever its value could change unexpectedly
- The optimizer must be careful to reload the variable every time it is used instead of holding a copy in a register

Only three types of variables should use `volatile`
- memory-mapped peripheral registers
- global variables (non stack variables) modified by an interrupt service routine
- global variables accessed by multiple tasks within a multi-threaded application

Syntax for `volatile` is
```c
volatile int loc1;  // loc1 is a volatile location
volatile int *ploc; // ploc points to a volatile location
```

`loc1` is a volatile value
`ploc` points to a volatile value

## `restrict`

The `restrict` type qualifier is an optimization hint for the compiler (the compiler can choose to ignore it)

It's used in pointer declarations as a type qualifier for pointers
- tells the compiler that a particular pointer is the only reference to the value it points to throughout its scope.
- the same value is not reference by any other pointer or variable within that scope
- the pointer is the sole initial means of accessing a data object
- tells the compilerit does note need to add any additional checks

With the `restirct` keyword usedi the compiler is free to look for computational shortcuts.

If a programmer uses `restrict` keyword and violate the aboce condition, result is undefined behavior.

**NOTE:** It's not supported by C++.

Syntax is

```c
int *restrict intPtrA;
int *restrict intPtrB;
```

Tells the compiler that, for the duration of the scope in which `intPtrA` and `intPtrB` are defined, they will never access the same value. Their use for pointing to integers inside an array is mutually exclusive.
