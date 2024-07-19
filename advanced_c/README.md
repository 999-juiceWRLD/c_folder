# Advanced C Class Topics

- Storage classes 
    - (`auto`, `register`, `static` and `extern`)
- Advanced data types
    - (`typedef`, variable length arrays, flexible array numbers, complex number types)

- Type qualifiers
    - `const`, `volatile` and `restrict`

- Bit manipulation
    - binary numbers and bits
    - bitwise operators (logical and shifting)
    - bitmasks and bitfields

- Advanced control flow
    - `goto`, `NULL`, comma operator
    - `setjmp` and `longjmp`

- More on Input and Output
    - `getchar`, `putchar`, `fgets`, etc.
    - `puts`, `sprint`, `fprintf`, `fflush`

- Advanced function concepts
    - variadic functions (variable number of arguments)
    - recursive functions
    - inline functions

- Unions
    - overview, defining and accessing `union` members

- Advanced preprocessor concepts
    - `#define`, `#pragma`, `#error`
    - conditional compilation (`#ifdef`, `#endif`, `#else`, `#elif`, `#undef`, etc)
    - include guards

- Macros
    - overview (vs. functions, when to use)
    - predefined macros
    - creating your own macros

- Advanced debugging and compiler flags
    - debugging with the preprocessor, more on gdb
    - core files, getting the stack trace
    - static analysis and profiling

- Static libraries and shared objects
    - overview, creation, dynamic loading

- Working with larger programs
    - dividing your program into multiple files and compiling multiple files

- Advanced pointers
    - double pointers (pointer to pointers)
    - function pointers
    - more on void pointers

- Useful C libraries
    - the `assert.h` library
    - general utilities library (`<stdlib.h>`), `exit`, `atexit`, `qsort`, `memcpy`, `abort`
    - date and time functions

- Data structures
    - Linked lists, stacks, queues, and trees

- Inter-process communication (Unix based Cygwin)
    - Overview (message queues, shared memory, piping)
    - forking and signals

- Threads (`pthread` — posix, not `<threads.h>` from C11)
    - overview, creating a thread
    - mutexes and semaphores
    - thread management (multi-threading, join, detach)

- Networking (unix based using Cygwin)
    - overview (client/server model)
    - creating server and client sockets
