# Advanced Data Types

## `#define` statement (constants)

The `#define` preprocessor directive (like all preprocessor directives), begin with the `#` symbol at the beginning of a line.

In C programming you can use this directive to define symbolic, or manifest, constants in a program.

Preprocessor directives run until the first newline following the `#`. A directive is limited to one line in length, and the combination backslash/newline is deleted befor preprocessor begins. You can spread the directive over several physical lines (these lines still constitute a single logical line).

Typically, `#define` statements appear first in the program (not required, they can appear anywhere in the program).

Most programmers group their `#define` statements at the beginning of the program (or inside an include file). They can be quickly referenced and shared by more than one source file. By convention, `#define` names are defined using only uppercase letters and underscores.

One of the primary uses of the `#define` statement is to assign symbolic names to program constants.

```c
// define the name YES and make it equivalent to 1
#define YES 1
```

`#define` statement has a special syntax. It has no equal sign used to assign values and a semicolon does not appear at the end of the statement.

A definition for a name can include more than a simple constant value, such as an expression.

```c
#define TWO_PI 2.0 * 3.141592654
```

Using a defined name for a constant value helps to make programs more readily extendable and more readable (e.g.):
- When you define an array, you must specify the number of elements in the array
- Subsequent program statements will likely use the knowledge of the number elements contained inside the array

There is a good chance that you will see statements in the program that use the fact that `dataValues` contains 1000 elements `for (int i = 0; i < 1000; i++) { ... }`

You would use the value 1000 as an upper bound for sequencin through the elements of the array. Suppose that you had to increase the size of the `dataValues` array from 1000 to 2000. Then you're going to have change all statements by hand used before. A better way of dealing with array bounds, which makes programs easier to extend, is to define a name for the upper array bound.

```c
#define MAXIMUM_DATAVALUES 1000

float dataValues[MAXIMUM_DATAVALUES];
for (int i = 0; i < MAXIMUM_DATAVALUES; i++) {
    // ...
}
// now change
#define MAXIMUM_DATAVALUES 2000
```

Another nice use of the `#define` statement is that it helps to make programs more portable from one computer system to another.

- It might be necessary to use constant values that are related to the particular computer on which the program is running (might have to do with the use of a particular computer memory address, a filename, or the number of bits contained in a computer word)

- If you want to execute a program on a different machine where an `int` contains 64 bits as opposed to 32, and you can use `#define` to set this.

In situations in which the program must be written to make use of machine dependent values. The `#define` statement can help isolate machine-dependent values from the program as much as possible, therefore it would be easier to port to another machine.

## `typedef`

The `typedef` keyword is an advanced feature in C that enbales you to create your own name for an existing data type.

To define a new type name with `typedef`:
- Write the statement as if a variable of the desired type were being declared
- Where the name of the declared variable would normally appear, substitute the new type
- In front of everything, place the keyword `typedef`

```c
typedef struct {
    char name[20];
    int age;
    char profession[20];
} Person;

// instead of: struct Person person
Person person;
```

**NOTE:** The `typedef` statement does not actually define a new type, it's only defining a **new type name**.

## Variable Length Arrays

Up until now, all the arrays that you have used have had fixed dimensions that you specify in the code (arrays are of constant size).

What if you don't know an array's size at compilation time? To handle this, you would have to use dynamic memory allocation with malloc.

A variable-length array is an array whose length, or size, is defined in terms of an expression evaluated at execution-time. It enables you to work with arrays in your programs without having to give them a constant size.

The term variable in variable-length array does not mean that you can modify the length of the array after you create it. Once created, a VLA keeps the same size. The term variable means that you can use a variable when specifying the array dimensions when first creating the array.

## Flexible Array Members

A flexible array member is a feature introduced in the C99 standard of the C programming language.

When using a structure, we can declare an array without a dimension whose size is flexible in nature. A flexible array member's size is variable (can be changed at runtime)

A flexible array member is a feature that allows you to create structures with a variable-sized array as the last member. This array has no specified size at compile time, and its size is determined dynamically at runtime. Flexible array members are useful when you need to allocate memory for variable-sized data structures.

Each struct can contain at most one flexible array member. Any struct containing flexible array member cannot be a member of another struct. A struct with a flexible array member cannot be statically initialized.
- It must be allocated dynamically
- You cannot fix the size of the flexible array member at compile time.

```c
struct vectord {
    short len;    // there must be at least one other data member
    double arr[]; // the flexible array member must be last
    // The compiler may reserve extra padding space here, like it can between struct members
};
```

It's debatable on whether it is good to practice to sue flexible array members. Some argue that you can just declare an array of size 0 or 1 and reallocate.
- In previous standards of the C language, it was common to declare a zero-sized array member instead of a flexible array member.
- Using non-standardized constructs to support flexible array members can yield undefined behavior which should be avoided.

A struct with a flexible array member reduces the number of allocations for it by half. Instead of two allocations for one struct object you need just 1, meaning less effort and less memory occupied.

If you don't use flexible array members, you have to allocate them with zero or one and then you have to do a realloc.

If you have to allocate a large number of struct instances, you can measurably improve the runtime and memory usage.

## Complex Number Types

A complex number is a number of the form $a + bi$
- $i$ is the square root of minus one
- $a$ and $b$ are real numbers

$a$ is called the real part, where $bi$ is called the imaginary part of the complex number. 

You can apply the following operations to complex numbers.
- Modulus: the modulus of a complex number is $\sqrt{a^2+b^2}$
- Equality: the complex numbers $a+bi$ and $c+di$ are equal if $a$ equals $c$ and $b$ equals $d$
- Addition: the sum of the complex numbers $a + bi$ and $c + di$ is $(a+c) + (b+d)i$
- Multiplication: the product of the complex numbers $a + bi$ and $c + di$ is $(ac-bd) + (ad+bc)i$
- Division: the division of the complex numbers $a + bi$ and $c + di$ is
$$ \frac{ac+bd}{c^2+d^2} + \frac{bc-ad}{c^2+d^2}i$$
- Conjugate: the conjugate of a complex number $a+bi$ is $a-bi$

There is a standard library called `<complex.h>` for making complex number operations.

`creal()` function returns the real part of a value of type `double complex` that is passed as the argument. The `cimag()` function returns the imaginary part.

```c
double complex cx = 1.0 + 3.0 * I;
double complex cy = 1.0 - 4.0 * I;

double real_part = creal(z1);
double imag_part = cimag(z1);
```

The `conj()` function returns the complex conjugate of its `double complex` argument.

## Designated Initializers

Designated initializers allow you to specify which elements of an array, structure or union are to be initialized by the values following an array index or a field by name (struct and union). It can be very useful if you have a struct that contains a large number of fields and you initially just want to set a few of them.

It provides a quick way of initialising specific elements in an array:

```c
int foo[10] = { [3]=1, [5]=2 };
```

The code above will set all elements of `foo` to 0, but element on the third index is 3 and the fifth index is 2.

```c
int foo[6] = { [3]=1, [5]=2 };

for (int i = 0; i < 6; i++) {
    printf("%d\n", foo[i]);
}

/* 
    output:
    0
    0
    0
    1
    0
    2
*/
```

To initalize a range of elements to the same value, write `[first ... last] = value`

```c
int some_arr[12] = 
```

The following initialization

```c
struct point p = { .y = 2, .x = 3 };
struct point p = { y: 2, x: 3 };
```

is equivalent to

```c
struct point p = { 3, 2 };
```
