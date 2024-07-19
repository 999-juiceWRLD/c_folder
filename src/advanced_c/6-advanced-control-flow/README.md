# Advanced Control Flow

## `goto` statement

You have probably previously heard about the `goto` statement and it's bad reputation. Virtually every computer language has such a statement.

A `goto` statement causes program control to jump to a particular line of code in your program. This branch is made immediately and unconditionally upon execution of the `goto`.

To identify where in the program the branch is to be made, a label is needed. A label is a name that is formed with the same rules as variable names. The label is place directly before the statement to which the branch is to be made and must appear in the same function as the `goto`.

Form:

```c
goto label; // ends in a semicolon
// ...
// ...
// ...
label: statement
```

### Problems with `goto`

Programmers who are lazy frequently abuse the `goto` statement to branch to other portions of their code.

The `goto` statement interrupts the normal sequential flow of a program. As a result, programs are harder to follow and thus harder to maintain.

Using many `goto`s in a program can make it impossible to follow. This style of programming is often derisively referred to as "spaghetti code". For these reasons, `goto` statements are not considered part of good programming style.

In principle, you never need to use the `goto` statement in a C program, however, some programmers develop bad habits or have learned programming languages where a `goto` was necessary i.e. fortran.

Most `goto`s are used for helping ifs, simulating if elses, controlling loops, or are just there because you have programmed yourself into a corner.
- Instead of skipping to the end of a loop and starting the next cycle using a `goto` statement, use `continue`.
- Instead of leacing a loop using a `goto` statement, use `break`
    - Actually, `break` and `continue` are specialized forms of a `goto` statement
    - The advantages of using them are that their names tell you what they are supposed to do
    - Also they do not use labels and thus, there is no danger of putting a label in the wrong place

### When to use the `goto` statement

There is one situation in which the `goto` statement can be very useful because it provides a way to avoid a lot of complicated logic. It can be used to exit deeply nested control structures efficiently.

```c
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
        for (int k = 0; k < 30; k++) {
            // loop body executed 10 * 20 * 30 = 6000 times
            // do something useful
            if (must_escape) {
                goto out;
            }
        }
    }
}

out:
    // statement following the nested loops
```

In the code above, you have a direct exit from the complete nest of loops without any complicated decision making in the outer loop levels.

## The `null` statement

The `null` statement is an expression statement with the expression missing. C permits a soltiary semicolon to be placed wherever a normal program statement can appear.

The `null` statement has the effect of doing nothing, but exists for syntactical reasons. Although the `null` statement might seem useless, it is often used by C programmers in `while`, `for`, and `do` loops.

It is useful when the syntax of the language calls for a statement but no expression evaluation.

Some examples.

The following for statement copies characters from the standard input to the standard output until the end of file is encountered.
```c
for (; (c = getchar()) != EOF; putchar(c)) {
    ;
}
```
The next for statement counts the number of characters that appear in the standard input.
```c
for (count = 0; getchar() != EOF; count++) {
    ;
}
```
When you want to find the index of first occurance of a certain character in a string.
```c
int a[50] = "the empire strikes back";
int i;

for (i = 0; a[i] != 't'; i++) {
    ; // null statement as no operation is required
}
```

## Comma Operator

C supports the use of a comma that can be used in expressions as an operator.
- has the lowest precedence of any C operator
- acts as a sequence of point

A binary operator that evaluates its first operand and discards the result, then evaluates the second operand and returns this value (and type). Because all operators in C produce a value, the value of the comma operator is that of the rightmost expression.

## `setjmp` and `longjmp` Functions

`setjmp()` and `longjmp()` are functions that let you perform complex flow-of-control in C.

Normal program flow in C follows function calls and branching constructs (`if`, `while`, etc). Functions `setjmp()` and `longjmp()` introduce another kind of program flow.

They are mainly used to implement exception handling in C (error recovery situations).
- `setjmp()` can be used like try (in languages like C++ and Java).
- `longjmp()` can be used like throw

Suppose there is an error deep down in a function nested in many other functions and error handling makes sense only in the top level function.
- would be very tedious and awkward if all the functions in between had to return normally and evaluate return values
- would be very tedious if you used a global error variable to determine that further processing doesn't make any sense or even would be bad

The above is a situation where `setjmp`/`longjmp` makes sense

### How it Works?

`setjmp()` saves a copy of the program counter and the current pointer to the top of the stack.
```c
int setjmp(jmp_buf j)

// use the variable j to remember were you are now
// must be called first
```

`longjmp` is then invoked after `setjmp`
```c
longjmp(jmp_buf j, int i)
```

- this says go back to the place that the `j` is remembering.
- restores the process in the state that it existed when it called `setjmp`
    - return the value of `i` so the code can tell when you actually got back here via `longjmp()`
- the contents of the `j` are destroued when it is used in a `longjmp()`

Often referred to as "unwinding the stack", because you unroll activation records from the stack until you get to the saved one.

The header file `<setjmp.h>` needs to e included in any source file that uses `setjmp` or `longjmp`

### Similarity with `goto`

Although it causes a branch, `longjmp` differs from the `goto`.
- A `goto` can't jump out of the current function in C.
- A `longjmp` can jump a long way away, even to a function in a different file. 
