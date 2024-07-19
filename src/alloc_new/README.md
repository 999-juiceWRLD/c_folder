# Dynamic Memory Allocation

Whenever you define a variable in C, the compiler automatically allocates the correct amount of storage for you based on the data type. Same also goes for pointers.

- It is frequently desirable to be able to dynamically allocate storage while program is running.

- If you have a program that is designed to read in a set of data from a file into an array in memory, you have three choices:

    - define the array to contain the maximum number of possible elements at compile time
    - use a variable-length array to dimension the size of the array at runtime
    - allocate the array dynamically using one of C's memory allocation routines

Using the dynamic memory allocation functions, you can get storage as you need it. This approach enables you to allocate memory as the program is executing.

- Dynamic memory allocation depends on the concept of a pointer and provides a strong incentive to use to use pointers in your code.

- Dynamic memory allocation allows memory for storing data to be allocated dynamically when your program executes. Allocationg memory dynamically is possible only because you have pointers available.

**NOTE:** The majority of production programs will use dynamic memory allocation.

Allocating data dynamically allows you to create pointers at runtime that are just large enough to hold the amount of data you require for the task (not wasting memory, vital).

There are two different data structures that you can store data: the stack or the heap. Dynamic memory allocation reserves space in a memory area called the heap.

The stack is another place where memory is allocated.

- Function arguments and local variables in a function are stored here

- When the execution of a function ends, the space allocated to store arguments and local variables is freed.

The memory in the heap is different in that it is controlled by you.

- When you allocate memory on the heap, it is up to you to keep track of when the memory you have allocated is no longer required.

- You must free the space you have allocated to allow it to be reused.

## `malloc`, `calloc`, `realloc`

### `malloc`

- The simplest standard library function that allocates memory at runtime is called `malloc()`

- You specify the number of bytes of memory that you want allocated as the argument returns the address of the first byte of memory that it allocated

- Returns the address of the first byte of memory that it allocated.

- Because you get an address returned, a pointer is the only place to put it.

```c
void *malloc(size_t size);

char *str = (char *) malloc(15); // 15 bytes of char
free(str);
```

Another code example:

```c
int *number_ptr = (int*) malloc(100);
```

- In the code above, we have requested 100 bytes of memory and assigned the address of this memory block to `number_ptr`.

- `number_ptr` will point to the first `int` location at the beginning of the 100 bytes that were allocated.

**NOTE:** An `int` is 4 bytes in my computer, therefore it can hold 25 int values. It would be better to remove the assumption that ints are 4 bytes.

To make `malloc` function allocate room for `N` ints:

```c
int *number_ptr = (int*) malloc(N * sizeof(int));
```

**NOTE:** Also notice the cast `(int*)`, which converts the address returned by the function to the type pointer to `int`. `malloc` returns a `void` pointer.

If the memory that you requested cannot be allocated for any reason:

- `malloc()` returns a pointer with the value `NULL`

- It is always a good idea to check any dynamic memory requested immediately using an if statement to make sure the memory is actually there before you try to use it.

```c
float *f_ptr = (float*) malloc(25*sizeof(float));
if (!f_ptr) {
    // code to deal with memory allocation failure
    // ...
}
```

When you allocate memory dynamically, you should always release the memory when it is no longer required. Memory that you allocate on the heap will be automatically released when your program ends. But it's better to explicitly release the memory when you are done with it, even if it's just before you exit from the program.

A memory leak occurs when you allocate some memory dynamically and you do not retain the reference to it, so you are unable to release the memory.

- It often occurs within a loop

- Because you do not release the memory when it is no longer required, your program consumes more and more of the available memory on each loop iteration and eventually may occupy it all.

- To free memory that you have allocated dynamically, you must still have access that references the block of memory.

To release the memory for a block of dynamically allocated memory whose address you have stored in a pointer:

```c
free(number_ptr);
number_ptr = NULL;
```

- As long as `number_ptr` contains the address that was returned when the memory was allocated, the entire block of memory will be freed for further use.

- You should always set the pointer to `NULL` after the memory that it points to has been freed.

### `calloc`

The `calloc()` function offers a couple of advantages over `malloc()`.

- It allocates memory as a number of elements of a given size

- It initializes the memory that is allocated so that all bytes are zero.

The `calloc()` function requires two argument values:

- Number of data items for which space is required

- size of each data item

```c
int *ptr = (int*) calloc(75, sizeof(int));
```

### `realloc`

The `realloc()` function enables you to reuse or extend memory that you previously allocated using `malloc()` or `calloc()`.

Expects two argument values:

- A pointer containing an address that was previously returned by a call `malloc()` or `calloc()`

- The size in bytes of the new memory that you want allocated

`realloc()` allocates the amount of memory you specify by the second argument.

- Transfers the contents of the previously allocated memory referenced by the pointer that you supply as the first argument

- Returns a `void *` pointer to the new memory or `NULL` if the operation fails for some reason.

The most important feature of this operation is that `realloc()` preserves the contents of the original memory area.

## Guidelines

1. Avoid allocating lots of small amounts of memory.

- Allocating memory on the heap carries some overhead with it.

- Allocating many small blocks of memory will carry much more overhead than allocating fewer larger blocks.

2. Only hang on to the memory as long as you need it.

- As soon as you are finished with a block of memory on the heap, release the memory.

3. Always ensure that you provide for releasing memory that you have allocated.

- Decide where in your code you will release the memory when you write the code that allocates it.

4. Make sure you do not inadvertently overwrite the address of memory you have allocated on the heap before you have released it.

- This will cause a memory leak. Be especially careful when allocating memory within a loop.

## Further Topics of Study

1. More on data types
    - defining you own types (`typedef`)

2. More on the preprocessor
    - string concatenation

3. More on `void *`'s

4. Static libaries and shared objects

5. Macros

6. Unions

7. Function pointers

8. Advanced pointers
    - pointers to pointers

9. Variable arguments to functions (variadic functions)

10. Dynamic linking (`dlm_open`)

11. Signals, forking, and inter-process communication
    - communicating via files, sockets, piping, etc.

12. Threading and concurrency

13. Sockets
    - sockets would be used if you wnated to connect to another computer and get data from that other computer

14. `setjmp` and `longjmp` for restoring state

15. More on memory management and fragmentation

16. More on making your program portable
    - we could use some of the POSIX standards that are available in C

17. Interfacing with kernel modules (drivers and ioctls)
    - use calls like IO controls
    - create drivers to talk with hardware directly

18. More on compiler and linker flags

19. Advanced use of gdb (GNU Debugger)

20. Profiling and tracing tools (gprof, dtrace, strace)
    - some tools that can analyze your code before you run you program to see if there's any dead code
    - tracing tools are all important tools you can use to see to help you debug and help you measure efficiency or how much memory you're using or the performance of you program

21. Memory debugging tools such as valgrind
    - this helps when you have race conditions, memory corruption problems

şu siteye sonra bak: [C `#ifndef` directive](https://www.techonthenet.com/c_language/directives/ifndef.php)