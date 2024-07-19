# Advanced Function Concepts

## Variadic Functions

The variation or change here is that we are dealing with unknown number of arguments for a function.

We typically use a variadic function when we do now know the total number of arguments that will be used for a function.
- One single function could potentiall have $N$ number of arguments
- A variadic function will contribute to the flexibility of the program that you are developing

The concept of a variadic function is already used in several C's built-in functions.
- In `printf` when you want to print one number or many numbers
    - `printf("some number: %d\n", number)`
    - `printf("num1: %d, num2: %d\n", number1, number2)`

If you look at the `stdio.h` header, you can see that this was implemented using variadic functions.

You may come up with a need to do this yourself from time to time, so the standard library `stdarg.h` provides you with routines to write some of you own variadic functions.

### Using a Variadic Function

A variadic function has two parts
- Mandatory arguments:
    - at least one is required and is the first one listed
    - order is very important
- Optional arguments
    - listed after mandatory arguments

When creating a variadic function, you must understand how to reference the variable number of arguments used inside the function
- you do not know how many there are and you cannot possibly give them names
- you can solve this problem indirectly, through pointers

The `stdarg.h` library header provides you with routines that are implemented as macros (look and operate like functions)
- you need to use these when implementing your own function with a variable number of arguments.

#### `va_list`

- Used in situations in which we need to access optional parameters and it is an argument list.
- Represents a data object used to hold the parameters corresponding to the ellipsis part of the parameter list

#### `va_start`

- Will connect out argument list with some argument pointer
- The list specified in `va_list` is the first argument and the second argument is the last fixed parameter

#### `va_arg`

- Will fetch the current argument connected to the argument list
- We would need to know the type of the argument that we are reading

#### `va_end`

- Used in situations when we would like to stop using are variable argument list (cleanup)

#### `va_copy`

- Used in situations for which we need to save our current location

### Creating a Variadic Function

To create a function with a variable number of arguments, perform the following steps.

1. Provide a function prototype using an ellipsis (three dots)
    - The ellipsis indicates that a variable number of arguments may follow any number of fixed arguments
    - Must have at least one fixed argument

```c
void f1(int n, ...);                // valid
int f2(const char *s, int k, ...);  // valid
char f3(char c1, ..., char c2);     // invalid, ellipsis not last
double f3(...);                     // invalid, no parameter
```

2. Create a `va_list` type variable in the function definition
    - Initialize the variable to an argument list
    - Need to copy the argument lsit to the `va_list` variable using `va_start`

```c
double average(double v1, double v2, ...) {
    va_list parg;   // pointer for variable argument list
    // some more code goes here...
    va_start(parg, v2);
    // some more code goes here...
}
```

3. First declare the variable `parg` of type `va_list`
    - Call `va_start()` with this as the first arghuemnt and specify the last fixed parameter `v2`  as the second argument
    - Effect of the call to `va_start()` is to set the variable `parg` to point to the first variable argument that is passed to the function when it is called
    - Still do not know what type of value this represents

4. Access the contents of the argument list using `va_arg()`
    - takes two arguments: a type `va_list` variable and a type name
    - the first time it is called, it returns the first item in the list
    - the next time it is called, it returns the next item, and so on
    - the type argument specifies the type of value returned (has to match the specification)

```c
double some_function(int lim, ...) {
    va_list ap;         // declare object to hold arguments
    va_start(ap, lim);  // initialize ap to argument list

    double tic = va_arg(ap, double); // retirieve first argument
}
```

- If the first argument is 10.0, the above code for `tic` works fine. If the argument is 10, the code may not work. The automatic conversion of `double` to `int` that works for assignment doesn't take place here

5. You should clean up by using the `va_end()` macro as you last step
    - essential to tidy up loose ends left by the process
    - takes a `va_list` variable as its argument, resets the `ap` pointer to `NULL`
    - if you omit this call, your program may not work properly
    - variable may not be usable unless you use `va_start` to reinitialize it

```c
va_end(ap); // clean up
```

### Summary Rules

- There must be at least one fixed parameter
- Must call `va_start()` to initialize the value of the variable argument list pointer in your function. This pointer must be declared as type `va_list`
- There needs to be a mechanism to determine the type of each argument. Either there can be a default type assumed or there can be a parameter that allows the argument type to be determined.
- For example, you could have an extra fixed argument in the `average()` function that would have the value 0 if the variable arguments were double and 1 if they were long

You must have a way to determine when the list of arguments is exhausted.
- for example, the last argument in the variable arhument list could have a fixed value called a *sentinel value* that can be detected because it's different from all the others.
- or the first argument could specify the count of the number of arguments in total or in the variable part of the argument list

You must call `va_end()` before you exit a function with a variable number of arguments. If you fail to do so, the function will not work properly.

#### `va_copy`

`va_arg()` does not provide a way to back up to previous arguments.

It is possible that you may need to process a variable argument list more than once.
- may be useful to preserve a copy of the `va_list` type variable
- use `va_copy()` two arguments are both type `va_list` variables, copies the second argument to the first

```c
va_list parg;
va_list parg_copy;
va_copy(parg_copy, parg);
```

- The first statement creates a new `va_list` variable, `parg_copy`
- The next statement copies the contents of `parg` to `parg_copy`
- You can then process `parg` and `parg_copy` independently to extract arguent values using `va_arg()` and `va_end()`

The `va_copy()` routine copies the `va_list` object in whatever state it is in
- If you have executed `va_arg()` with `parg` to extract argument values from the list prior to using the `va_copy()` routine, `parg_copy` will be in an identical state to `parg` with some argument values already extracted.

Do not use the `va_list` object `parg_copy` as the destination for another copy operation before you have executed `va_end()` for `parg_copy`

### Variadic Functions Challenge

Write a program that creates a variadic function that will allow a programmer to add any amount of numbers (integers) that they would like to be added together.

In order to know how many numbers are being passed to this varaidic function, you can use the first argument as the number of arguments.

## Inline Functions

Normally, a function call has overhead when being invoked. It takes execution time to set up the call, pass arguments, jump to the function code, and return.

C99 added the concept of inline functions to try and avoid the amount of overhead that comes along with invoking a function.

The point of making a function inline is to hint to the compiler that it is worth making some form of extra effort to call the function faster than it would otherwise.
- usually the compiler will substitute the code of the function into its caller (eliminating the need for a call and return sequence)
- the program no longer calls that function, the compiler replaces every call to an inline function with the code body of that function.

The inline declaration is only advice to the compiler, which can decide to ignore it. This may cause the compiler to replace the function call with inline code and/or perform some other sorts of optimizations, or it may have no effect.

Inline functions can improve the runtime performance of a program (not guaranteed). Whether an inline function serves you purpose in a positive or in a negative way depends purely on your code design and ils largely debatable.

It is a common misconception that in-lining always equals faster code. If there are many lines in inline function or there are more function calls, then in-lining can cause wastage of space.

Inline functions can increase the size of the program. It increases file size as the same function code is copied again and again in the program wherever it is called.

Making a function inline has no effect on the logic of the program from the user's perspective.

It is suggested to only declare functions as inline if they are short and called frequently. For a long function, the time consumed in calling the function is short compared to the time spent executing body of the function. No great savings in time using an inline version.

You can declare an inline function by placing the keyword `inline` before the function declaration.

```c
inline void randomFunction();
```

there are different places to create inline function definintions (same file or header file). For the compiler to make inline optimizations, it has to know the contents of the function definition. The inline function definition has to be in the same file as the function call (internal linkage)

Should always use the inline function specifier along with the static storage-class specifier (using `extern` less portable). Inline functions are usually defined before their first use in a file (definition also acts as a prototype)

```c
inline static void foo() { // inline definition/prototype
    // do something
}
```

If you have a multi-file program, you need an inline definition in each file that calls the function. The simples way to accomplish this is to put the inline function definition in a header file. Include the header file in those files that use the function.

```c
// foo.h
#ifndef FOO_H_
#define FOO_H_
inline static void foo() {
    // do something
}
#endif
```

An inline function is an exception to the rule of not placing executable code in a header file. Because the inline function has internal linkage, defining one in several files does not cause problems.

### _Noreturn Functions

C11 added a second function specifier (in addition to `inline`)

The purpose of this specifier is to inform the user and the compiler that a particular function will not return control to the calling program when it completes execution
- informing the user helps to prevent misuse of the function
- informing the compiler may enable it to make some code optimizations

Just like the `inline` function specifier, the `_Noreturn` function specifier is a hint to the compiler.
- Using the `_Noreturn` function specifier does not stop a function from returning to its caller (only a promise made by the programmer to the compiler to allow it some mroe degree of freedom to generate optimized code)
- The degree of acceptance is implementation defined

The `exit()` function is an example of a `_Noreturn` function. Once `exit()` is called, the calling function never resumes.

Note that this specifier is different from the `void` return type. A typical `void` function does return to the calling function. It just does not provide an assignable value.

If a function specified with the `_Noreturn` function specifier violates its pormise and eventually returns to its caller (by using an explicit return statement or by reaching end of function body)
- the behavior is undefined
- you must not return from the function

Compilers are encouraged, but not required, to produce warnings or errors when a `_Noreturn` function appears to be capable of returning to its caller.

The `_Noreturn` kewyord appeats in a function declaration. The `_Noreturn` specifier may appear more than once in the same function declaration.
- the behavior is the same as if it appeared once

This specifier is typically used through the convenience macro `noreturn`.
- provided in the header file `<stdnoreturn.h>`
- using `_Noreturn` or `noreturn` is fine and equivalent