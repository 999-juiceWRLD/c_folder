# File Handling in C

C views a file as a continuous sequence of bytes.

- Each byte can be read individually
- Corresponds to the file structure in the Unix environment

Text data is written as a sequence of characters organized as lines (each line ends with a newline), where binary data is written as a series of bytes exactly as they appear in memory (image data, music encoding — not readable).

You can write any data you like to a file. Once a file hass been written, it just consists of a series of bytes.

In C programming, the size of a `char` is always 1 byte. This is defined by the C standard, and it remains consistent across different platforms. Therefore, a `char` variable in C occupies 8 bits. A sequence of 12 bytes in a binary file could be 12 characters, 12 8-bit signed integers, 12 8-bit unsigned integers, etc.

In binary mode, each and every byte of the file is accessible.

A stream is an abstract representation of any external source or destination for data.

- The keyboard, the command line on your display, and files on a disk are all examples of things you can work with as streams.
- The C library provides functions for reading and writing to or from data streams.

## Accessing Files

A program references a file through a file pointer.

- You assosciate a file pointer with a file programmatically when the program is run.
- Pointers can be reused to point to different files on different occasions.

A file pointer points to a struct of type `FILE` that represents a stream. Contains information about the file:

- Whether you want to read or write or update the file
- The address of the buffer in memory to be used for data
- A pointer to the current position in the file for the next operation

If you want to sue several files simultaneously in a program, you need a separate file pointer for each file. There is a limit to the number of files you can have open at a time, defined as `FOPEN_MAX` in `stdio.h` (it's 20).

`fopen`'s parameters:

| Parameter | Description                                                                           |
|-----------|---------------------------------------------------------------------------------------|
| filename  | The name of the actual file you want to open (or create), like `filename.txt`         |
| mode      | A single character, which represents what you want to do with the file, `w`: writes to a file, `r`: reads from a file, `a`: appends new data to a file |

If the file cannot be opened for some reason, the `fopen` will return `NULL`.

## Renaming a File

Rename a file using `rename()` function. The integer that is reuturned will be 0 if the name changes, and nonzero otherwise.

```c
int rename(const char *oldname, const char *newname);
```

The file must not be open when you call `rename()`, otherwise it will fail. Also, the path of the file must be entered correctly.

## Closing a File

Close files with `fclose`. Returns EOF (`int`) if an error occurs. EOF is a special character called the end-of-file character, defined in `stdio.h` as a negative integer that is usually equivalent to the value -1. Returns 0 if successful.

**NOTE:** You must close a file before attempting to rename it or remove it.

## Deleting a File

This function takes a string as a parameter, which represents the name of the file to be deleted. The function returns 0 if the file is deleted successfully, Otherwise, it returns a non-zero value.

## Reading from a File

The `fgetc()` function reads a character from a text file that has been opened for reading. It takes a file pointer as its only argument and returns the character read as type `int`.

The function `getc()`, which is equivalent to `fgetc()` is also available (`getc()` can also be implemented as a macro, whereas `fgetc()` is a function). It's virtually identical to `fgetc()`.

You can read the contents of a file again when necessary.

- The `rewind()` function positions the file that is specified by the file pointer argument at the beginning.

```c
FILE *f;
rewind(f);
```

You can use `fgets()` function to read from any file or stream.

```c
char *fgets(char *str, int nchars, FILE *stream)
```

The function reads a string into the memory. Characters are read until either a '`\n`' is read or `nchars - 1` characters have been read from the stream, whichever occurs first.

If there is no error, `fgets()` returns the pointer, `str`. If there is an error, `NULL` is returned. Also, reading `EOF` causes `NULL` to be returned.

You can get formatted input from a file by using the standard `fscanf()` function.

```c
int fscanf(FILE *stream, const char *format, ...)
```

The first argument to this function is the pointer to a FILE object that identifies the stream.

The second argument to this function is the format. A C string that contains one or more of the following items:

- whitespace character
- non-whitespace character
- format specifiers

usage is similar to `scanf`, but from a file. Function returns the number of input items successfully matched and assigned.

## Writing Characters to a Text File

The simples write operation is provided by `fputc()`.

```c
int fputc(int ch, FILE *pfile);
```

The function writes the character specified by the first argument to the file identified by the second argument (file pointer).

- Returns the character written if successful.
- Return EOF if failure.

The `putc()` function is equivalent to `fputc()`. Difference between them is that `putc()` function may be implemented as a macro, whereas `fputc()` is a function.

```c
int fputs(const char *str, FILE *file)
```

The first argument is a pointer to the character string that is to be written to the file. The second argument is the file pointer.

We can write formatted output to a file. The standard function for formatted output to a stream is `fprintf()`.

```c
int fprintf(FILE *stream, const char *format, ...)
```

The first argument is the file pointer. The second argument to this function is the format a C string that contains one or more of the following items:

- Whitespace character
- Non-whitespace character
- Format specifiers
- Usage is similar to `printf`, but, to a file.

If successful, the total number of characters written is returned. Otherwise, a negative number is returned.
