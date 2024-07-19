# Data Structures

In programming, you try to match the data type to the needs of a programming problem
- you would use the int type to represent the number of pants you own
- you would use the float or double type to represent your average cost per pair of pants

In other scenarios, the data could be a list of items. No basic C type matches data for a list of items

We would need to define a structrue to represent individual items
- we would then create a couple methods for tying together a series of structures to form a list
- we use C's capabilities to design a new data type that matches our needs

## Abstract Data Type (ADT)

An ADT is a type whose vehavior is defined by a set of value and a set of operations (sounds like a structure in C).

The definition of ADT only mentions what operations are to be performed
- not how these operations will be implemented
- does not specify how data will be organized in memory nor what algorithms will be used for implementing the operations

It is called "abstract" because it gives an implementation-independent view
- the process of providing only the essentials and hiding the details is knowns as abstraction
- a contract for a type of data structure

Examples of ADT's include lists, stacks, trees, etc.
