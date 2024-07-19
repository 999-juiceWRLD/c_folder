# Unions

A union is a derived type (similar to a structure) with members that share the same storage space.
- Sometimes the same type of construct needs different types of data

Used mainly in advanced programming applications where it is necessary to store different types of data in the same storage area.
- Can be used to save space and for alternating data
- A union does not waste storage on variables that are note being used

Just like structs, each element in a union is called member.

You can define a union with many members
- Only one member can contain a value at any given time, so only one access of a member at a given time

The members of a union can be of any data type. In most cases, unions contain two or more data types.

It is your responsibility to ensure that the data in a union is referenced with the proper data type. Referencing data in a union with a variable of the wrong type is a logic error.

The operations that can be performed ona union are:
- Assignin a union to another union of the same type
- Taking the address (&) of a union variable
- Accessing union members

Unions are particularly useful in embedded programming. There are situations where direct access to the hardware/memory is needed

You could use a union to represent a table that stores a mixture of types in some order. You could create an array of unions that store equal-sized units — each of which can hold a variety of data types

A union could represent a file containing different record types. A union could represent a network interface containing different request types.

Although structs are similar to unions, the memory allocated for a union is quite different than for a struct.

Every time you create an instance of a struct, the computer will lay out the fields in memory, one after the other. It allocates storage space for all its members separately.

With a union, all the members have an offset of zero (union). A union is created with enough space for its largest field. The programmer then decides which value will be stored there.

If you have a union called quantity, with fields called count, weight, and volume, whether you set the count, weight, or volume field, the data will go into the same space in memory.

## Structs vs. Unions

Although unions are similar to structures, they are used for entirely different situations.

- You should use a structure when you construct should be a group of other things.
- You should use a union when your construct can be one of many different things but only one at a time.
- Unions are typically used in situations where space is premium but more importantly for exclusively alternate data.
- Unions ensure that mutually exclusive states remain mutually exclusive.
- Unions share a common storage space where structures store several data types simultaneously
    - a structure can hold an int and a double and a char
    - a union can hold an int or a double or a char

|                           | Structure                                                                                                                                                                             | Union                                                                                                                                                                                      |
|---------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Keyword                   | The keyword `struct` is used to define a structure                                                                                                                                    | The keyword `union` is used to define a union                                                                                                                                              |
| Size                      | When a variable is associated with a structure, the compiler allocates the memory for each member. The size of structure is greater than or equal to the sum of sizes of its members. | When a variable is associated with a union, the compiler allocates the memory by considering the size of the largest memory. So, size of union is equal to the size of the largest member. |
| Memory                    | Each member within a structure is assigned unique storage area of location.                                                                                                           | Memory allocated is shared by individual members of union.                                                                                                                                 |
| Value Altering            | Altering the value of a member will not affect other members of the structure.                                                                                                        | Altering the value of any of the member will alter other member values.                                                                                                                    |
| Accessing Members         | Individual member can be accessed at a time.                                                                                                                                          | Only one member can be accessed at a time.                                                                                                                                                 |
| Initialization of Members | Several members of a structure can be initialized at once.                                                                                                                            | Only the first member of a union can be initialized.                                                                                                                                       |

The memory occupied by a union will be large enough to hold the largest member of the union.

```c
union Data {
    int i;
    float f;
    char str[20];
} data;
```

`Data` type will occupy 20 bytes of memory space because this is the maximum space which can be occupied by a character string.

## Challenge

You must define a union named student that consists of the following three elements:
- `char letterGrade`
- `int roundedGrade`
- `float exactGrade`

Your program should declare two union variables inside the main function (variable 1 and variable 2).

Your program should assign random values to variable 1
- You then need to display each value for each member of this union
- You should notice that something is wrong
