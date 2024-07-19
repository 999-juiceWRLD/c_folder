# The Preprocessor

The process of creating a C program involves many different steps.

- preprocessor
- compilation
- assembler
- linker
- loader

A program called the preprocessor is invoked before any code gets compiled in the C programming language.
- a separate step in the compilation process
- not part of the compiler

The C preprocessor is essentially a text substitution tool. Instructs the compiler to do required preprocessing before the actual compilation.

The C preprocessor mainly performs three tasks on your code.

1. Removes all the comments.
- A comment is written only for other engineers who need to understand your code. It is of no use to a machine.
- The preprocessor removes all comments as they are not required in the execution of the program.

2. Includes all of the files from various libraries that the program needs to compile.
- `#include` directive (includes the contents of the library file specified)

3. Expansion of macro definitions
- We will discuss macros later.
- Small function that do not contain as much overhead to process as a regular function

## Preprocessor Directives

Commands used by the preprocessor are called preprocessor directives and they begin with `#` symbol
- Must be the first nonblank character
- Should begin in the first column

We have already some of them (e.g. `#define` and `#include`)

In the upcoming lectures, we will learn about more of them.
- Conditional compilation commands: `#ifdef`, `#ifndef`, `if`, `#elif`, `#else`, `#endif`
- Other directives: `#undef`, `#pragma`, and `#error`

The preprocessor offers operators which can help in creation of macros. We will discuss macros later.

These operators are used in the context of the `#define` directive. We will learn:

- Continuation operator `\`
- Concatenation operators
    - `#` when used within a macro definition, converts a macro parameter into a string constant
    - `##` within a macro definition combines two arguments. It permits two separate tokens in the definition to be joined into a single token
    - `defined()`: simplifies the writing of compound expressions in certain macro directives

## Conditional Compilation

The C preprocessor offers a feature known as conditional compilation. It is often used to create one program that can be compiled to run on different computer systems.

If you had a large program that had many dependencies on specific hardware or software.
- You might end up with many defines whose values would have to be changed when the program was moved to another computer system
- You can help reduce this problem by incorporating the values of these defines for each different machine into the program by using the conditional compilation capabilities of the preprocessor

It is also used to switch on or off various statements in the program
- Debugging statements that print out the values of various variables
- Trace the flow of program execution

Conditional compilation enables you to control the execution of preprocessor directives and the compilation of program code
- Each of conditional preprocessor directives evaluates an identifier or a constant integer expression.
- Cast expressions, sizof expressions and enumeration constant cannot be evaluated in preprocessor directives

### Conditional Compilation Commands

Includes a set of commands that tell the compiler to accept or ignore blocks of information or code according to conditions at the time of compilation.

- The conditional preprocessor construct is much like the if selection statement

- Every `#if` construct ends with an `#endif`

Directive `#ifdef` and `#ifndef` are provided as shorthand for
- `#if defined(name)`
- `#if !defined(name)`

Multiple-part conditional preprocessor construct may be tested with `#elif` and `#else`

### `#ifdef` directive

This directive checks whether an identifier is currently defined
- Identifier can be defined by a `#define` directive or on the the command line

To set an identifier, here is an example using the `#define` directive

```c
#define UNIX 1
// or
#define UNIX
```

Most compiler also permit you to define a name to the preprocessor when the program is compiled
- use the special option `-D` to the compiler command

```bash
gcc -D UNIX program.c
```

### `#ifdef` and `#endif`

The general form of the `#ifdef` directive is

```c
#ifdef IDENTIFIER
```

Identifiers cannot be any keyword or enumeration constants. If the identifier specified has been defined by the preprocessor
- compile all the code up to the next `#else` or `#endif`, whichever comes first
- if there is an `#else`, all code from the `#else` to the `#endif` is compiled if the identifier is not defined

The `#endif` directive ends the scope of the `#if`, `#ifdef`, `#ifndef`, `#else`, or `#elif` directives.

### `#ifndef`

This directive checks to see if an identifier is not currently defined, which is the negative for `#ifdef`. It is often used to define a constant if it's not already defined.

`#ifndef` has the following syntax:

```c
#ifndef SIZE
    #define SIZE 100
#endif // SIZE
```

### `#if`

You can use the `#if` directive to test the value of a constant expression. A constant expression is specified through a `#define` statement or via the command line when the program is compiled.

The general form of the `#if` directive:

```c
#if constant_expression
```

The operand must be a constatn intgeger expression that does not contain any increment (++), decrement (--), sizeof, pointer (*), address (&), and cast operators. You can also use relational and logical operators with the `#if` directive.

The constant expression is subject tot text replacement and can contain references to identifiers defined in previous `#define` directives.

If an identifier used in the expression is not currently defined, the compiler treats the identifier as though it were the constant zero.

### `#else`

To complement the `#ifdef`/`#ifndef` and `#if` directives, you have the `#else` directive.
- It works exactly the same way as the else statement does
- Identifies a group of directives to be executed or statements to be included if the `#ifdef`/`#ifndef` or `#if` condition fails

The form `#ifdef`/`#ifndef`/`#if` - `#else` is much like that of the C if else
- main difference is that the preprocessor does not recognize the braces ({}) syntax of marking a block
- it uses the `#else` (if any) and the `#endif` (which must be present) to mark blocks of directives. These conditional structures can be nested.

With an `#else` directive, everything from the `#else` to the `#endif` is done if the identifier is not defined.

```c
#ifdef UNIX
    #define DATADIR "/uxn1/data"
#else
    #define DATADIR "\usr\data"
#endif
```

The above has the effect of defining `DATADIR` to "/uxn1/data" if the symbol UNIX has been previously defined and to "\usr\data" otherwise.

You are allowed to put one or more spaces after the `#` that begins a preprocessor statement.

A value can also be assigned to the define name on the command line.

```c
gcc -D DATADIR=\c\my_data
```

### `#elif`

This directive is used for multiple-choice selections
- similar to the combined use of the else-if statements in C
- optional

The `#elif` directive has the general form

```c
#elif constant_expression
```

```c
#define UK      1
#define France  2
#define Germany 3
#define Country US

int main() {
    #if Country == US || Country == UK
        #define Greeting "Hello."
    #elif Country == France
        #define Greeting "Bonjour."
    #elif Country == Germany
        #define Greeting "Guten tag."
    #endif
}
```

## Include Guards and `#undef`

The `#ifndef` directive is commonly used to prevent multiple inclusions of a file. Many include files to other files, so you may include a file explicitly that another include has already included.

This is a problem because some items that appear in include files, such as declarations of structure types, can appear only once in a file.
-p revents multiple definitions of the same variable/function/macro

The standar C header files uses the `#ifndef` technique to avoid multiple inclusions.

One problem is to make sure the identifier you are testing has not been defined elsewhere
- use the filename as the identifier (using uppercase, replacing periods with an uderscore, and using an underscore)

```c
#ifndef _STDIO_H_
#define _STDIO_H_
// contents
#endif // _STDIO_H_
```

or

```c
#ifndef THINGS_H_
    #define THINGS_H_
    // rest of the file
#endif // THINGS_H_
```

The definition in the first header file included becomes the active definition and subsequent definitions in other header files are ignored.
- the first time the preprocessor encounter this include file, `THINGS_H_` is defined, so the preprocessor skips the rest of the file
- the next time the preprocessor encounters this file, `THINGS_H_` is defined, so the preprocessor skips the rest of the file.
- ensures that the contents of a header file cannot be included more than once into a source file

Using an include directive makes it impossible for the contents of any `include.h` to appear more than once in a source file.

You should always protect code in your own header files in this way.

### `undef`

Another flexibility that you have with preprocessor directives is the ability to undefine an identifier you have previously defined.

On some occasions, you might need to cause a defined name to become undefined which cancels an earlier `#define` definition. You can accomplish this using the `#undef` directive.

```c
// #undef name

#undef LINUX
```

The above removes the definition of `LINUX`. Subsequent `#ifdef LINUX` statements will evaluate as `FALSE`.

## `#pragma` and `#error`

### `#pragma`

The `#pragma` directive lets you place compiler instructions in your source code
- lets you request special behavior from the compiler

This directive is most useful for programs that are unusually large or that need to take advantage of the capabilities of the capabilities of a particular compiler

`#pragma` can be used
- to control the amount of memory set aside for automatic variables
- to set the strictness of error checking
- to enable nonstandard language features

The `#pragma` (pragmatic information) directive is part of the standard
- the meaning of any `#pragma` depends on the software implementation of the standard that is used
- generally, each compiler has its own set of pragmas

Syntax is:

```c
#pragma token_name
```

`#pragma` is usually followed by a single token which represents a command for the compiler to obey.

There are only a limited list of supported tokens for each standard/compiler
- the set of commands that can appear in `#pragma` directibes is different for each compiler
- need to reference the compiler documentation
- a pragma not recognized by the implementation is ignored

We will see the following pragmas (which are available in the gcc compiler)
- `#pragma GCC dependency`
- `#pragma GCC poison`
- `#pragma GCC system_header`
- `#pragma once`
- `#pragma GCC warning`
- `#pragma GCC error`
- `#pragma message`

#### `#pragma GCC dependency`

This allows you to check the relative dates of the current file and another file. If the other file is more recent than the current file, a warning is issued.

This pragma is useful if the current file is derived from the other file, and should be regenerated.

```c
#pragma GCC dependency "parse.y"
#pragma GCC dependency "/usr/include/time.h" rerun fixincludes
```

#### `#pragma GCC poison`

This directive is used to remove an identifier completely from the program.

Sometimes, there is an identifier that you want to remove completely from your program, and make sure that it is never used.

To enforce this , you can poison the identifier with this pragma.
- followed by a list of identifiers to poison
- if any of those identifiers appear anywhere in the source after the directive, an error will be displayed by the compiler

```c
#pragma GCC poison printf sprintf fprintf
sprintf(some_string, "hello"); // will produce an error
```

#### `#pragma GCC system_header`

The `#pragma GCC system_header` tells the compiler to consider the rest of the current include file as a system header.
- code that comes before the `#pragma` in the file is not affected
- this pragma takes no arguments

System headers are header files that come with the OS or compiler.

GCC gives code found in system headers special treatment.

This pragma can affect the severity of some diagnostic messages
- all warnings are suppressed while GCC is processing a system header
- macros defined in a system header are immune to a few warning wherever they are expanded

#### `#pragma warning`, `errors` and `message`

`#pragma once`
- specifies that the header file containing this directive is included only once even if the programmer includes it multiple times during a compilation
- works similar to using include guards
- a less-portable alternative to using `#ifndef` to guard the contents of header files against multiple inclusions

`#pragma GCC warning "message"`
- causes the preprocessor to issue a warning diagnostic with the text "message"
- message contained in the pragma must be a single string literal

`#pragma GCC error "message"`
- causes the preprocessor to issue an error with the text "message"
- message contained in the pragma must be a single string literal

`#pragma message "message"`
- prints a string as a compiler message on compilation
- the message is informational only (not a warning or an error)

### `#error`

One of the least used but potentially most useful features of the C preprocessor is the ANSI-specified `#error` directive

The `#error` directive causes the preprocessor to issue an error message that includes any text in the directive
- error message is a sequence of characters separated by spaces
- you do not have to enclose the text in quotes
- the message is optional
