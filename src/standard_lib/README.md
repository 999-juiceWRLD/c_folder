# Standard C Library

## `stddef.h`

`stddef.h` contains some standard definitions.

| Define                         | Meaning                                                                                                                    |
|--------------------------------|----------------------------------------------------------------------------------------------------------------------------|
| `NULL`                         | A null pointer constant                                                                                                    |
| `offsetof (structure, member)` | The offset in bytes of the member `member` from the start of the structure `structure`, the type of the result is `size_t` |
| `ptrdiff_t`                    | The type of integer produced by subtracting two pointers                                                                   |
| `size_t`                       | The type of integer produced by the `sizeof` operator                                                                      |
| `wchar_t`                      | The type of the integer required to hold a wide character                                                                  |

## `limits.h`

`limits.h` contains various implementation-defined limits for character and integer data types.

| Define       | Meaning                                                                                               |
|--------------|-------------------------------------------------------------------------------------------------------|
| `CHAR_BIT`   | Number of bits in a `char`                                                                            |
| `CHAR_MAX`   | Maximum value for object of type `char` (127 if `sign` extension is done on `char`'s, 0 otherwise)    |
| `CHAR_MIN`   | Minimum value for object of type `char` (-127 if `sign` extension is done on `char`'s, 255 otherwise) |
| `SCHAR_MAX`  | Maximum value for object of type `signed char` (127)                                                  |
| `SCHAR_MIN`  | Minimum value for object of type `signed char` (-127)                                                 |
| `UCHAR_MAX`  | Maximum value for object of type `unsigned char` (255)                                                |
| `SHRT_MAX`   | Maximum value for object of type `short int` (32767)                                                  |
| `SHRT_MIN`   | Minimum value for object of type `short int` (-32767)                                                 |
| `USHRT_MAX`  | Maximum value for object of type `unsigned short int` (65535)                                         |
| `INT_MAX`    | Maximum value for object of type `int` (32767)                                                        |
| `INT_MIN`    | Minimum value for object of type `int` (-32767)                                                       |
| `UINT_MAX`   | Maximum value for object of type `unsigned int` (65535)                                               |
| `LONG_MAX`   | Maximum value for object of type `long int` (2147483647)                                              |
| `LONG_MIN`   | Minimum value for object of type `long int` (-2147483647)                                             |
| `ULONG_MAX`  | Maximum value for object of type `unsigned long int` (4294967295)                                     |
| `LLONG_MAX`  | Maximum value for object of type `long long int` (9223372036854775807)                                |
| `LLONG_MAX`  | Minimum value for object of type `long long int` (-9223372036854775807)                               |
| `ULLONG_MAX` | Maximum value for object of type `unsigned long long int` (18446744073709551615)                      |

## `stdbool.h`

`stdbool.h` file contains definitions for working with Boolean variables (`type _Bool`).

| Define  | Meaning                                         |
|---------|-------------------------------------------------|
| `bool`  | Substitute name for the basic `_Bool` data type |
| `true`  | Defined as 1                                    |
| `false` | Defined as 0                                    |
