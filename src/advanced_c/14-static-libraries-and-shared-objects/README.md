# Static Libraries and Shared Objects

You have already seen the power of standard libraries of C.
- standard header files (`stdio.h`, `stdlib.h`)
- math, string and utility functions

Now it is time to use that power for your own code
- you will learn how to create your own libraries and reuse the same code across several programs
- you will learn how to share code at runtime with dynamic libraries (shared objects)

You will be able to write code that you can scale and manage simply and efficiently.

## Libraries

A library is a collection (group) of header files and implementation files, exposed for use by other programs
- interface expressed in a header file
- implementation expressed in a C file

A library consists of or more object files, which consist of object code.

C functions that can be shared by more than one application should be broken out of an application's source code an compiled and bundled into a library.

Libraries may call functions in other libraries such as the standard C or math libraries to do various tasks.

A programmer has the interface file (headers) to figure out how to use a library.

## Advantages of Libraries

Libraries are useful because they allow for fast compilation times
- you do have to compile all sources of your dependencies when compiling your application. With a library, you can just link to a shared object.
- allows application vendors a way to simply release an API to interface with an application

Libraries also allow for modular development and separation of components.

Sofware reuse is a huge benefit of libraries.

Version management - libraries can cohabitate old and new versions on a single system.

Component specialization - specialized developers can focus on their code competency on a single library.

## Linking

When a C program is compiled, the compiler generates object code (`.o` or `.obj`). After generating the object code, the compiler also invokes the linker. Linking is the process of collecting and combining multiple object files in order to create a single executable file.

One of the main tasks for linker is to make the code of library functions (eg. `printf()`, `scanf()`, etc.) available to you program.

A linker can accomplish this task in two ways
- by copying the code of library function to your object code
- by making some arrangements so that the complete code of library functions is not copied, but made available at run time

Static linking is the result of the linker making copy of all used library functions to the executable file.

Dynamic linking does not require the code to be copied, it is done by just placing the name of the library in the binary file (linking happens when the program is run, when both the binary file and the library are in memory)

## Static Linking

When you link your application to another library at compile time, the library code is part of your application.

The primary advantage of static linking is the speed
- there will be no symbol (a program entity) resolution at runtime
- every piece of the library is part of the binary image (executable)

Once everything is bundled into your application, you don't have to worry that the client will have the right library (and version available on their system).

Static linking creates larger binary files that utilize more disk space and main memory. Once the library is linked and the program is created, you have no way of changing any of the library code without rebuilding the whole program (more time consuming to fix bugs).

## Dynamic Linking

Dynamic linking defers much of the linking process until a program starts running
- performs the linking process "on the fly" as programs are executed in the system

Libraries are loaded into memory by programs when they start.

During compilation of the library, the machine code is stored on your machine
- when you recompile a program that uses this library, only the new code in the program is compiled (does not recompile the library into the executable file like in static linking)

The main reason for using dynamic linking of libraries is to free your software from the need to recompile with each new release of a library.

Dynamic linking is the more modern approach, and has the advantage of a much smaller executable size.

Dynamic linking trades off more efficient use of the disk and a quicker linking phase for a small runtime penalty.

Dynamic linking helps overall performance in two ways:
1. it saves on disk and virtual memory
    - libraries are only mapped in to the process when needed
2. all executables dynamically linked to a particular library share a single copy of the library at runtime
    - ensures that libraries mapped into memory are shared by all processes using them
    - provides better I/O and swap space utilization and is sparing of physical memory, improving overall system throughput

## Library Types

There are two C library types which can be created.

1. Static libraries:
    - uses static linking (compile-time, becomes part of the application)
    - each process gets its own copy of the code and data
    - known as an archive

2. Shared object libraries
    - dynamically linked at runtime. shared objects are not included into the executable component but are tied to the execution
    - code shared, data is specific to each process

There is also ghe concept of a dynamically loaded/unloaded shared object library that is linked during execution using the dynamic linking loader system functions.

## Library Conventions

Dynamic libraries are called `lib<something>.so`
- have a filename of the form `libname.so` (version numbers may be appended to the name)
- the library of thread routines is called `libthread.so`

Static libraries are called `lib<something>.a`
- has a filename of the form `libname.a`
- ".a" library is conceptyally the same as the windows ".lib" libraries

You can identify your libraries by looking at the header files you have used
- a good hint is to study the `#include`s that your program uses
- each header file that you include potentially represents a library against which you must link

### Summary

Static libraries have the advantage of speed
- all the code to execute the file is in one executable file, with little to virtually zero compatibility issues

Static libraries are larger in size because the file has to be recompiled every time when adding new code to the executable.

For shared objects, only one copy of the shared library is kept in memory
- making it much faster to compile programs and significatnly reducting the size of the executable program

Shared objects have a slower execution time compared to static libraries. Shared objects also may have compatibilitiy issues if a library is changed without recompiling the library into memory