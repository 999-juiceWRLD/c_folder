1. avoid allocating lots of small amounts of memory.

- allocating memory on the heap carries some overhead with it.
- allocating many small blocks of memory will carry much more overhead than allocating fewer larger blocks.

2. only hang on to the memory as long as you need it.

- as soon as you are finished with a block of memory on the heap, release the memory.

3. always ensure that you provide for releasing memory that you have allocated.

- decide where in your code you will release the memory when you write the code that allocates it.

4. make sure you do not inadvertently overwrite the address of memory you have allocated on the heap before you have released it.

- this will cause a memory leak.
- be especially careful when allocating memory within a loop.