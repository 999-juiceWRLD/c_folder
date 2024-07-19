# Storage Classes

Storage classes are used to describe the features of a variable/function. It includes the scope, visibility and lifetime helps us to trace the existence of a particular variable during the runtime of a program.

The lifetime of a variable is the time period during which variable exists in computer memory.
- Some exist briefly, some are repeatedly created and destroyed, and others exist for the entire execution of the program

The scope of the variable is where the variable can be referenced in a program. Some can be referenced throughout a program, others from only portions of a program.

A variable's visibility (or the linkage) determines for a multiple source file program whether the identifier is known only in the current source file or in any source file with proper declarations.

C provides four storage classes, indicated by their storage class specifiers:
- `auto`
- `register`
- `extern`
- `static`

| Storage Specifier | Storage      | Initial Value | Scope                 | Life                    |
|-------------------|--------------|---------------|-----------------------|-------------------------|
| `auto`            | Stack        | Garbage       | Within block          | End of block            |
| `extern`          | Data Segment | Zero          | Global multiple files | Till the end of program |
| `static`          | Data Segment | Zero          | Within block          | Till the end of program |
| `register`        | CPU Register | Garbage       | Within block          | End of block            |

The four storage class specifiers can be split into two storage durations
- automatic storage duration
- static storage duration

## `auto`

Keyword `auto` is used to declare variables of automatic storage duration
- Created when the block in which they are defined is entered
- Exists while the block is active
- Destroyed when the block is exited

Local variables are declared within a function body or block of code, they have automatic storage duration by default.

These variables are known as automatic local variables:
- They are automatically created each time the function is called
- Their values are local to the function

The values of a local variable can only be accessed by the function in which the variable is defined
- It's values cannot be accessed by any other function
- If an initial value is given to a variable inside a function, that initial value is assigned to the variable each time the function is called

The C compiler assumes by default that any variable defined inside a function is an automatic local variable. The keyword `auto` is seldom used.

**NOTE:** C++ has repurposed the `auto` keyword for a quite different use, so simply not using `auto` as a storage-class specifier is better for C/C++ compatibility. However, you can make your intentions perfectly clear by explicitly using the keyword `auto` before the definition of the variable. You might do this to document that you are intentionally overriding and external variable definition, or that it is important not to change the variable to another storage class.

Automatic storage is a means of conserving memory.
- Automatic variables exist only when they are needed
- They are created when the function in which they are defined is entered
- They are destroyed when the function is exited

Automatic storage is an example of the principle of least privilege — allowing access to data only when it is absolutely needed

**NOTE:** Storage classes precede the type of the variable.

```c
// STORAGE_CLASS DATA_TYPE VAR_NAME;
auto double x, y;
```

## `extern`

The `extern` storage class simply tells us that a variable is defined elsewhere in the program (but not within the same block where it is used!)

An `extern` variable is a global variable initialized with a legal value where it is declared in order to be used elsewhere.

The main purpose of using `extern` variables is that they can be accessed between two different files which are part of a larger program. Functions contained in separate files can communicate through extern variables.

The `extern` storage class is used to give a reference of a global variable that is visible to ALL the program files.

Inside the module that wants to access the external variable:
- The variable data type is preceeded with the keyword `extern` in the declaration
- Tells the compiler that a globally defined variable from another file is to be accessed.

## `static`

The `static` storage class can be used on local and global variables, as well as functions.

When applied to local variables it instructs the compiler to keep the variable in existence during the life-time of the program.

When applied to global variables, the static modifier causes that variable's scope to be restricted to the file in which it is declared.

When applied to functions, the static function can be called only from within the same file as the function appears.

### Automatic and Static Variables (Local Statics)

We know that when you normally declare a local variable inside a function:
- You are declaring automatic local variables
- Recall that the keyword auto can, in fact, precede the declaration of such variables (optional)
- An automatic variable is actually created each time the function is called and destroyed upon exit of the function

Automatic local variables can be given initial values:
- The value of the expression is calculated and assigned to the automatic local variable each time the function is called
- Because an automatic variable disappears after the function completes execution, the value of that variable disappears along with it
- The value an automatic variable has when a function finishes execution is guaranteed not to exist the next time the function is called

Static variables have a property of preserving their value even after they are out of their scope
- Static variables preserve the value of their last use in their scope
- No new memory is allocated because they are not redeclared
- Their scope is local to the function to which they were defined

Static variables should not be declared inside a structure. The C compiler requires the entire structure elements to be places together. Memory allocation for structure members should be contiguous.

## `static`

## `register`

A processor register (CPU register) is one of a small set of data holding places that are part of the computer processor. A register may hold an instruction, a storage address, or any kind of data.

The `register` storage class is used to define local variables that should be stored in a register instead of RAM (memory). This makes the use of register variables to be much faster than that of the variables stored in the memory during the runtime of the program.

The `register` storage class should only be used for variables that require quick access.
- If the variables which are most frequently used in a C program
- If a function uses a particular variable heavily

The keyword `register` hints to the compiler that a given variable can be put in a register.
- It is the compiler's choice to put it in a register or not
- MIGHT be stored in a register depending on hardware and implementation restrictions
- Generally, compilers themselves do optimizations and put the variables in register

The keyword `register` is used to define `register` storage class. Both local varaibles and formal parameters can be declared as `register` variables.

This storage class declares register variables which have the same functionality as that of the auto variables (the lifetime of a register variable remains only when control is within the block)

The variable stored in a register has a maximum size equal to the register size. You cannot obtain the address of a register variable using pointers (cannot have the unary '&' operator applied to it, as it does not have a memory location)