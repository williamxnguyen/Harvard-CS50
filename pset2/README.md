# Memory (Lecture Notes)

## Compiling 
- **"Compiling"** source code into machine code is actually made up of smaller steps:
        - preprocessing 
        - compiling 
        - assembling
        - linking 

## Debugging

Looking at a specific program:
```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i <= 10; i++)
    {
        printf("#\n");
    }
}
```
- I'm only intended to only see 10 `#`s, but there are 11 when I run the program. If we didn't know what the problem is (as I write the program) -- I could add another print line to help me. 

```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i <= 10; i++)
    {
        printf("i is %i\n", i);
        printf("#\n");
    }
}
```
        - Now, I see that `i` started at 0 and continued until it was 10, but it should have stopped at 10. 

## Arrays
- In memory, we can store variables one after another, back-to-back. And in C, a list of variables stored, one after another in a contiguous chunk of memory, is called an array.

```c



