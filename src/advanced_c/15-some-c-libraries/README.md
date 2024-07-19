# Useful C Libraries

## Assert

The assert library is designed to help with debugging programs, defined in `assert.h`.

The `assert()` macro enables you to insert test of arbitrary expressions in your program (it's essentially a runtime check).

It takes as its argument an integer expression. The argument is a relational or logical expression.

The program will be terminated with a diagnostic message if a specified expression is false during execution.
- the error message is written to the standard error stream (stderr`) that displays the test that failed, the name of the file containing the test, and a line number.
- `abort()` function is invoked which terminates the program.

Assertions are often used for critical conditions in a program.
- If certain conditions are not met, disaster will occur
-you would want to be sure that the program does not continue when this error occurs

Assertions are not meant asa substitute for error handling during normal runtime conditions
- use should be limited to finding logic errors

```c
assert(some_variable < some_count);
```

## Switching Off Assertions

Assertions can be switched off by defining the symbol `NDEBUG` before the `#include` directive for `assert.h`.

```c
#define NDEBUG  // switch off runtime assertions
#include <assert.h>
// ...
```

This code snippet will cause all `assert()` macros in your code to be ignored. With some nonstandard systems, assertions are disabled by default, in which case you can enable them by undefining `NDEBUG`.

```c
#undef NDEBUG   // switch on assertions
```

By including the directive to undefine NDEBUG, you ensure that assertions are enabled for your source file. `#undef` must appear before the `#include` directive for `assert.h` to be effective.

## Compile-Time Assertions

C11 added a feature that does a compile-time check (this can cause a program not to compile). The `assert.h` header makes `static_assert` an alias for the C keyword `_Static_assert`. This is more compatible with C++, which uses `static_assert` as its keyword for this feature.

`static_assert` is treated as a declaration statement. Unlike most kinds of C statements, it can appear either in a function or external to a function.

The `static_assert()` macro enables you to output an error message during compilation
- message includes a string literal that you specify
- whether or not the output is produced depends on the value of an expression that is a compile time constant

Takes two arguments:
- first is a constant integer expression
- second is a string

```c
static_assert(constant_expression, string_literal);
```

When the constant expression evalueates to zero, compilation stops and the error message is output.

## Compile Time Assertions

The `static_assert()` enables you to build checks into your code about your implementation.

Suppose your code assumes that type char is an unsigned type. You could include this static assertion in the source file.

```c
static_assert(CHAR_MIN == 0, "Type char is a signed type. Code won't work.");
```

The above will cause compilation to be halted and an error message that includes your string to be produced when type char is signed.

## General Utilities (`stdlib.h`)

There are several dozens of functions which facilitate every C programmer in writing programs for different requirements.

Programming in C requires any C program to use these various different functions. We have discussed many of these functions (`strcpy`, `printf`, `scanf`, etc).

All these function are put together in the standard library. Functions performing somewhat similar tasks are put together in same header file
- functions performing input and output are put together in `stdio.h` header
- functions performing string manipulations are defined in `string.h` header

These standard library functions help make your code more portable and more efficient.

### `exit()`

Program execution is automatically terminated whenever the last statement in `main()` is executed (or when executing a return from `main()`).

At times, you might want to force the termination of a program earlier than the above.
- when an error condition is detected by a program:
  - input error
  - a file to be processed by the program cannot be opened

The exit function forces a program to terminate as if it executed normally
- no matter from what point you are executing
- invoked automatically upon return from main

```c
int exit(int status);
```

The above statement has the effect of terminating (exiting from) the current program.

Any open files are automatically closed by the system
- flushes all output streams
- closes all open streams
- closes temporary files created by calls to the standard I/O function `tmpfile()`

The integer value status is called the exit status, and has the same meaning as the value returned from `main()`
- `EXIT_FAILURE(symbolic_constant)` represents an integer value that you can use to indicate the program has failed (non-zero)
- `EXIT_SUCCESS(symbolic_constant)` represents an integer value that you can use to indicate it has succeded (0)

When a program terminates simply by executing the last statement in main, its exit status is undefined. You should exir or return from `main()` with a defined exit status.

### `atexit()`

The `atexit()` function allows you to specify particular functions to be called when `exit()`.

Takes as an argument a pointer to a function (the function name).

```c
int atexit(void (*function)(void);
```

To use the `atexit()` function
- pass it the address of the function you want called on exit
- registers this function in a list of functions to be executed when `exit()` is called
- up to 32 functions may be registered for execution at program termination

The functions registered by `atexit()` should be type void functions taknig no arguments. They cannot have arguments and cannot return a value.

Typically, the functions invıked, would perform housekeeping tasks
- updating a program-monitoring file
- resetting environmental variables

### `abort()`

We just mentioned that the atexit and exit functions relate to normal termination of a program.

The abort function causes abnormal program termination
- raises the `SIGABRT` signal
- returns an implementation defined code indicating unsuccessful termination

The abort function follows the philosophy of "fail hard and fail often".

This function causes a noticeable failure because it will dump core and generate a core file.

When using the abort function, following may occur
- file buffers are not flushed
- streams are not closed
- temporary files are not deleted

Functions passed to `atexit()` are not called.

**NOTE:** This will not cause the program to terminate if `SIGABRT` is being caught by a signal handler passed to signal and the handler does not return. 

```c
void abort(void);
```

### `qsort`

The quick sort method is one of the most effective sorting algorithms
- particularly for larger arrays
- partitions arrays into even smaller sizes untile the element level is reached

First, the array is divided into two parts, with every value in one partition being less than every value in the other partition. This process continues until the array is fully sorted.

The name for the C implementation of the quick sort algorithm is `qsort()`
- sorts a data array pointed to by a function pointer (comparison function) passed into the qsort function

`qsort()` and the comparison function use void pointers for generality
- you have to tell `qsort()` explicitly how large each element of the array is
- you have to convert its pointer arguments to pointers of the proper type for your application

```c
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
```

The first argument is a pointer to the beginning of the array to be sorted
- can refer to any kind of array because of use of void pointer

The second argument is the number of items to be sorted
- converts this value to type `size_t`

The third argument is the size of each element
- because `qsort()` converts its first argument to a void pointer, `qsort()` loses track of how big each array element is
- to compensate, you must tell `qsort()` explicitly the size of the data object (this argument)

The final argument is the address of the function to be used for comparing elements

The signature of the comparison function is

```c
int (*compar)(const void *, const void *)
```

A pointer to a function that returns an int and that takes two arguments
- each of which is a pointer to type const void
- these two pointers point to the items being compared

The comparison function should return the following
- a poisitve integer if the first item should follow the second value
- a zero if the two items are the same
- a negative integer if the second item should follow the first