# Overview

Most programs in the real world that you will have to develop will not be as small or as simple.

It is imperative to learn the proper techniques for dealing with larger programs

- You need to divide the problem into multiple sub-problems and then try to tackle it one by one.

- C provides all the features necessary for the efficient development of large programs.

The most common beginner mistake is to jump in directly and and try to write all the necessary code into a single file and later try to debug or extend later. This approach is doomed to fail and would require rewriting from scratch.

When you start dealing with larger programs, they must be organized around multiple files.

Large programming applications frequently require the efforts of more than one programmer.

- As the number of statements in the program increases, so does the time it takes to edit the program and to subsequently recompile it.

- Having everyone work on the same source file, or even on their own copy of the same source file is unmanageable.

C programs do not require that all the statements for a particular program be contained in a single file.

- You can enter your code for a particular module into one file, for another module into a different file, and so on.

The term module refers either to a single function or to a number of related functions that you choose to group logically.

Programmers usually start designing a program by dividing the problem into easily managed sections.

- Each of these sections might be implemented as one or more functions.

- All functions from each section will usually live in a single file.

The file contains the definition of each function
- should create a header file for each of the C files (will have the same name as the C file)

## Compiling Multiple Source Files from the Command Line

Suppose you have conceptually divided your program into three modules `mod1.c`, `mod2.c`, and the  `main()` routine into the file `main.c`.

To tell the system that these three modules actually belong to the same program. You include the names of all three files when you enter the command to compile the program.

```bash
$ gcc mod1.c mod2.c main.c -o dbtest
```

The above has the effect of separately compiling the code contained in `mod1.c`, `mod2.c` and `main.c`.

- Errors discovered in `mod1.c`, `mod2.c`, and `main.c` are separately identified by the compiler.

We already understand that the compiler generates intermediate object files for each source file that it compiles. It places the resulting object code from compiling `mod1.c` into the `mod1.o` by default (or `.obj` on Windows). 

You can use the following sequence to compile a three-module program using the incremental compilation technique:

```bash
$ gcc -c mod1.c # compile mod1.c => mod1.o
$ gcc -c mod2.c # compile mod2.c => mod2.o
$ gcc -c main.c # compile main.c => main.o
```

- If you extend the preceding examples to programs that consist of many modules, you can see how this mechanism of separate compilations can enable you to develop large programs efficiently.

```bash
$ gcc -c legal.c
$ gcc legal.o makemove.o exec.o enumerator.o evaluator.o display.o -o superchess
```

The above will compile a program consisting of six modules, in which only the module `legal.c` needs to be recompiled.

## Makefiles

An introduction to makefiles.

If you still want to work from the command line, the makefile utility is a tool that you might want to learn how to use.

- It's not a part of the C language
- Very helpful when developing larger programs
- Can help speed your development time

This powerful utility allows you to specify a list of files and their dependencies in a special file known as a *Makefile*.

The make program automatically recompiles files only when necessary (based on the modification times of a file).

If make finds that your source `.c` file is newer than your corresponding object `.o` file, it automatically issues the commands to recompile the source file to create a new object file.

## Header Files

Include files are great for grouping all your commonly used definitions inside a file. You can then simply include the file in any program that needs to use those definitions.

## Heap and Stack Memory Allocation

There are three forms of memory that you can use in your program.
- static
- stack
- heap

Each type of memory determines where and how it is stored.

It is very important to understand the differences/advantages/disadvantages of how/where your memory is stored. It gives you a strategic advantage for creating scalable programs.

You have to decide when to use memory from the stack vs. heap or static memory based on each problem you are trying to solve.

Static memory persists throughout the entire life of the program. It's usually used to store things like global variables, or variables created with the `static` clause

### Stack

Stack is a special region of memory that stores temporary variables.
- It is used to store variables that are created inside of a function
- Easier to keep track of because the memory is only locally available in the function.

Stack is a LIFO data structure that is managed and optimized by the CPU.
- It's a linear data structure
- There's no need to manage the memory yourself. Variables are located and freed automatically.

The stack grows and shrinks as variables are created and destroyed inside a function.
- Every time a function declares a new variable, it is *pushed* onto the stack
- Every time a function exits, all of the variables pushed onto the stack by that function, are freed (deleted)
- Once a stack variable is freed, that region of memory becomes available for other stack variables

There is a limit on the size of variables that can be stored on the stack.

If a program tries to put too much information on the stack, stack overflow will occur. This happens when all the memory in the stack has been allocated, and further allocations begin overflowing into other sections of memory. It also occurs in situations where recursion is incorrectly used.

### Heap

It's the opposite of the stack. It's a hierarchical data structure.

- Heap is a large pool of memory that can be used dynamically.
- Memory is not automatically managed. There are more free-floating region of memory.
- Heap is managed by the programmer. The memory is accessed through the use of pointers. You have to explicitly allocate (`malloc()`) and deallocate (`free()`) the memory.
- Failure to free the memory when you're finished with it will result in memory leaks (memory that is still "being used", and not available to other processes).

There are generally no restrictions on the size of the heap (or the variables it creates) other than the physical size of memory in the machine.

Variables created on the heap are accessible anywhere in ithe program (essentially they're global in scope). Heap memory is slightly slower to be read from and written to.

Use the heap:
- When you need to allocate a large block of memory (a large array or a big struct)
- When you need to keep that variable around a long time
- When you need variables like arrays and structs that can change size dynamically (arrays that can grow or shrink as needed)

Use the stack:
- When you are dealing with realtively small variables that only need to persist as long as the function using them is alive

### Appendix

**NOTE:** Overview adlı videonun (23. video) 12. dakikasında linux/unix için terminalden derlemesi var. Senin yaptığınla aynı.

header guards???

Also look for: [Why are #ifndef and #define used in C++ header files?](https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files)

[makefile tutorial](https://makefiletutorial.com/)

[window manager](https://superuser.com/questions/291298/window-manager-vs-desktop-environment-vs-window-system-whats-the-difference)
