# Macros

A macro is essentially a piece of code based on the `#define` directive
- technically, we have already learned about macro's when we learned about symbolic constants

When you first learn about macros, you probably think that they are nothing more than a function call with some strange syntax
- and you would mostly be right, they "behave" similar to normal functions

Macros are a text processing feature and are "expanded" and replaced by macro definitions.

```c
#define MACRO macro_body
```

Each `#define` line has three parts
- the first part is the `#define` directive itself
- the second part is your chosen abbrebiation, known as a macro name
- the third part (the remainder of the line) is termed the replacement list or body (preprocessor replaces macro name with the macro body)

```c
#define PX printf("x is %d.\n", x);
```

## Conventions

- You should use capital letters for macro function names
    - not as widespread as that of using capitals for macro constants
    - one good reason for using capitals is to remind yourself to be alert to possible macro side effects

There are no spaces in the macro name, however, spaces can appear in the replacement string (macro_value). Macros are also not terminated by a semicolon.

Macros run until the first newline following the #
- limited to one line in length by default unless you use the backlash operator (\) for continuation

## Macros vs Functions

Many tasks can be done by using a macro with arguments or by using a function.

As we have learned before, macros are essentially functions, but, with different syntax. It behaves just like a function.

However, there are some huge differences (under the hood) and without understanding these differences, you might be using either one when you should not be.

You must understand that macros are pre-processed which means that all the macros would be processed before your program compiles
- functions are not preprocessed, they are compiled

So, now the question becomes, what are the differences and when should I use one vs. the other? There is no hard-and-fast rule

The main consideration becomes a trade off between time and space.

### Speed

A macro is faster than a function
- program control must shift to where the function is and then return to the calling program (thakes longer than inline code)

If you intent to use a macro instead of a function primarily to speed up a program, first try to determine whether it is likely to make a significant difference

A macro that is used once in a program probably will not probably will not have any noticeable improvement in running time.

A macro inside a nested loop is a much better candidate for speed improvements
- many systems offer program profilers to help you pin down where a program spends the most time

When you call a function

### Space

When you call a function, it has to allocate some data (a newly allocated stack frame)
- macros do not have this overhead
- macros insert code directly into the program (textual substitution)

A macro produces inline code (a statement in your program)
- if you use the same macro 20 times, you get 20 lines of code inserted into your program
- if you use a function 20 times, you have just one copy of the function statements in your program (less space is used)

Functions are preferred over macros when writing large chunks of code.

### Other Considerations

Macros have an advantage in that they do not have to worry about variable types
- deal with character strings, not with actual values
- a macro can be used equally well with an int or float (just substitute the argument you pass them)

Functions give you type checking (if a function expects a string, but you give it an int, you will get an error)

Macros are somewhat trickier to use than regular functions because they can have odd side effects if you are not careful
- some compilers limit the macro definition to one line, and it is probably best to observe that limit, even if your compiler does not

It is much harder to debug a macro than when you use a function
- a function can be stepped through by the debugger and a macro cannot
- when a macro fails, the only way you can find out what the problem is, is by looking at its definition and trying to find out what happened (you can tell gcc to tell you how everything expands using `gcc -E source_file.c`)

### Alternatives

- Inline functions are the best alternative to macros

- When you add the inline keyword in front of a function, you are hinting to the compiler to embed the function body inside the caller (just like a macro)

- Inline functions can be debugged

- Inline functions also have type checking

- However, the inline keyword is merely a hint to the compiler, it is not a strict rule and the compiler can decide to ignore the hint

- Macros will always have their palce and are not going away

## Creating Your Own Macros

As mentioned previously, there are two ways of defining macros, one of which looks like a function and one which does not
- symbolic constants (constants represented as symbols)
- function macros (operations defined as symbols)

The below definition does not look like a function (symbolic constant):

```c
#define NONFMAC some text here
```

- Defines a macro and some replacement text (the replacement text for a macro is any text on the line after the identifier in the `#define` directive)

- After the definition, the macro can be used as follows:

```c
NONFMAC
/* some text here */
```

Leading or trailing white space around the replacement text is discarded. It's name is simply replaced by its replacement text.

## Function Macros

The below definition looks more like a function.

```c
#define FMAC(a, b) a here, then b

#define macro_name(list_of_identifiers) substitution_string
```

The above defines a macro and some replacement text
- the list of identifiers separated by commas (a, b) appears between the parentheses following the macro_name (FMAC)
- each of these identifiers can appear one or more times in the substitution string

After the definition, the macro can be used as follows:

```c
FMAC(first text, some more)
/* First text here, then some more */
```

- Leading or trailing white space around the replacement text is discarded.
- It ges a bit trickier with the function macro because of the (identifiers) or formal parameters.

## Macros with Arguments

You can create function-like macros that look and act much like functions when you pass data to them (arguments)
- looks very similar to a function because the arguments in parentheses, and these arguments then appear in the replacement portion

Function-like macro definitions have one or more arguments in parentheses, and these arguments then appear in the replacement portion.

To create a macro with arguments, put them in parentheses separated by commas after the macro name.

```c
#define SQUARE(X) X * X
```

Can be used in program like the below:

```c
z = SQUARE(2);
```

Looks like a function call, but it does not necessarily behave identically.

## Macros with Arguments

```c
#define macro_name(list_of_identifiers) substitution_string
```

A macro that contains arguments has its arguments substituted in the replacement text when the macro is expanded.
- the replacement text for a macro is any text on the line after the identifier in the `#define` directive
- the replacement text replaces the identifier and argument list in the program

Use should use parentheses around each argument and arounf the definition as a whole
- ensures that the enclosed terms are grouped properly in an expression (avoid operator precedence)

## Preprocessor Operators

The preprocessor includes the following four operators which can make it easier to create macros
- \
- defined
- #
- ##

The backslash (\) operator allows for the continutation of a macro to the next line when the macro is too long for a single line.
- a macro is always a single, logical line

The `defined()` operator is used in constant expressions to determine if an identifier is defined using `#define`.

The # and ## operators are used for concatenation
- often useful to merge two tokens into one while expanding macros, called token pasting or token concatenation

The (`#`) operator is used within a macro definition
- causes a replacement text token to be converted to a string surrounded by quotes

The (`##`) operator performs token pasting
- concatenates two tokens
- when a macro is expanded, the two tokens on either side of each `##` operator are combined into a single token

### (\) operator

A macto is normally confined to a single line
- the macro continuation operator (\) is used to continue a macro that is too long for a single line

```c
#define mix(x, y) \
    (x < y ? x : y)
```

The above macro definition continues on the second physical line with the first nonblank character found
- you can position the text on the second line to wherever you feel is the most readable
- the \ must be the alst character on the line, immediately before you press enter
- result is seen by the compiler as a single, logical line

### `defined()` operator

The defined operator is used in constant expressions to determine if an identifier is defined using `#define`.

If the specified identifier is defined, the value is true (non-zero). If the symbol is not defined, the value is false (zero).

It can also be used in `#if` statements.

```c
#if defined(DEBUG)
// some code
#endif
```

```c
// the same as the above, but, using `#ifdef`
#ifdef DEBUG
// some code
#endif
```


### `defined()` operator (example)

```c
#if defined(WINDOWS) || defined(WINDOWSNT)
    #define BOOT_DRIVE "C:/"
#else
    #define BOOT_DRIVE "D:/"
#endif

int main(void) {
    printf("Here is the boot drive path: %s\n", BOOT_DRIVE);
}
```

- The above code will display as output "C:/" if either WINDOWS or WINDOWSNT is defined. Output will be "D:/" otherwise.

### # and ## operators

If you place a # in front of a parameter in a macro definition
- creates a constant string out of the macro argument when the macro is invoked
- literally inserts double quotation marks around the actual macro argument

```c
#define str(x) # x
// causes the subsequent invocation
str(testing)
```

To be expanded into — "testing".

```c
printf(str(Programming in C is fun.\n));
// is therefore equivalent to
printf("Programming in C is fun.\n");
```

Some more examples.

```c
#define HELLO(X) printf("Hello," #X "\n");
```

The # operator must be used in a macro with arguments because the operand of # refers to an argument of the macro.

#### The ## operator

This operator is used in macro definitions to join two tokens together
- preceded (or followed) by the name of a parameter to the macr
- takes the actual argument to the macro that is supplied when the macro is invoked and creates a single token out of that argument and whatever token follows (or precedes) the ##

Usually both will be identifiers, or one will be an identifier and the other a preprocessing number
- when pasted, they make a longer identifier

Two tokens that don't together form a valid toekn cannot be pasted together
- you cannot concatenate `x` with `+` in either order

This operator is most useful when one or both of the tokens comes from a macro argument. If either of the tokens next to an `##` is a parameter name
- replaced by its actual argument before `##` executes

```c
#define TOKENCONCAT(x, y) x ## y // TOKENCONCAT(O, K) is replaced by OK in the program
```

#### Another Example

It is possible to concatenate a macro argument with a constant prefix or suffix to obtain a valid identifier as in

```c
#define make_function(name) int my_ ## name (int foo) {}

make_function(bar)

// this will define a function called my_bar()
```

```c
#define eat(what) puts("I'm eating " #what " today.")
eat(fruit) // output: I'm eating fruit today.
```

Which in turn will be interpreted by the C parser as a single string constant.

#### Another Example

Consider a C program that interprets named commands. There probably needs to be a table of commands, perhaps an array of structures declared as follows:

```c
struct command {
    char *name;
    void (*function)(void);
};

struct command commands[] = {
    { "quit", quit_command },
    { "help", help_command },
    // ...
};
```

It would be cleaner not to have to give each command name twice, once in the string constant and once in the function name. A macro which takes the name of a command as an argument can make this unnecessary
- the string constant can be created with stringizing, and the function name by concatenating the argument with `_command`

```c
#define COMMAND(NAME) { #NAME, NAME ## _command }

struct command commands[] = {
    COMMAND(quit),
    COMMAND(help),
    // ...
};
```

## Predefined Macros

There are usually a considerable number of standard preprocessing macros defined by the compiler (defined in the documentation).

Standard C provides predefined symbolic constants
- begin and end with two underscores
- cannot be used in `#define` and `#undef` directives

- `__FILE__`: represents the current file name (string)
- `__LINE__`: represents the current line number of the current source code (an integer constant)
- `__func__`: the name of any function when placed isnide a function of the current file (not part of the standard)
- `__DATE__`: the date the source file was compiled (a string of the form "mmm dd yyyy" such as "Jan 19 2002")
- `__TIME__`: the time the source file was compiled (a string literal of the form "hh:mm:ss")
- `__STDC__`: used to indicate if the compiler supports standard C by returning the value 1