# Week 3 Notes
## String 

For the bottom program, it looks like no matter what I type for the strings, the program things it is _different_. **Why?**
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get two strings
    string s = get_string("s: ");
    string t = get_string("t: ");

    if (s == t)
    {
        printf("same\n");
    }
    else
    {
        printf("different\n");
    }
}
```
- `string` is not actually a data type in C. The word "string" is common but there is no way to store strings in C. 
- Recall that strings are just an **array of characters**, thus when I ran the above program, the 2 string inputs from user might be stored in memory in the following way:
    - "W|I|L|L|\0"
    - "J|A|M|E|S|\0"
    - Each character is in one byte, and somewhere **_we have bytes in memory containing the values for each of the string._**

- It turns out, **_each byte in memory has a numeric location, or address._**
    - For example, the character `W` might have an memory address of `100` and `J` might have ended up in `900` (depending on what parts of memory were available, or free)

![](https://cs50.harvard.edu/college/2018/fall/weeks/3/notes/strings_with_addresses.png)

    - Notice that, since each string is an array of characters, **each character within the array has consecutive addresses, since they're stored NEXT TO EACH OTHER IN MEMORY.**
    - However, different strings themselves might have very different addresses

- Thus, `get_string` ACTUALLY returns just the address, **memory location** (A SINGLE VALUE). It is not returning the actual string but rather the memory address. 
    - This is the reason why when comparing strings, you get `false` since you're actually comparing 2 different memory addresses even if they are the same strings. 
    - Different strings end up in different memory locations.
    - **You can now assume, that comparing 2 "strings" actually just compares two addresses (which will always be different) since it stores in a new place each time -- even if characters stored at those addresses are the same.**

**Note:** Data types such as char, bool, ints are returned as their **values** (it also has a memory location) but the different between them and strings is that strings do not return as their values (for e.g. "string") but rather the memory location. 

- Other data types in C, such as `int`, or `float`s are generally passed and stored as their values since they are always a **fixed number of bytes**
    - **_Strings however, are passed as their addresses, since they could be really long._**
    - Strings are identified as their starting address -- need to know how long they are...
    
You can fundamentally compare each string by comparing each character one at a time:
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool compare_strings(string a, string b);

int main(void)
{
    // Get two strings
    string s = get_string("s: ");
    string t = get_string("t: ");

    // Compare strings for equality
    if (compare_strings(s, t))
    {
        printf("same\n");
    }
    else
    {
        printf("different\n");
    }
}

bool compare_strings(string a, string b)
{
    // Compare strings' lengths
    if (strlen(a) != strlen(b))
    {
        return false;
    }

    // Compare strings character by character
    for (int i = 0, n = strlen(a); i < n; i++) 
    {
        // Different
        if (a[i] != b[i])
        {
            return false;
        }
    }

    // Same
    return true;
}
```
    - Firstly, comparing the string's lengths and `return false` if both strings are not of same length. Then checking each character of the array
    
## Char *
- A `string` is actually a synonym for a `char *`. 
    - The `*` means that the _data type is an address._
    - So a `char *` is an address to a `char`, and such a variable type is called a _pointer_.
    - **A pointer is an address.**
    - Thus, I can replace `char *` where I've been using string. 
    
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool compare_strings(char *a, char *b);

int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Compare strings for equality
    if (compare_strings(s, t))
    {
        printf("same\n");
    }
    else
    {
        printf("different\n");
    }
}

bool compare_strings(char *a, char *b)
{
    // Compare strings' lengths
    if (strlen(a) != strlen(b))
    {
        return false;
    }

    // Compare strings character by character
    for (int i = 0, n = strlen(a); i < n; i++)
    {
        // Different
        if (a[i] != b[i])
        {
            return false;
        }
    }

    // Same
    return true;
}
```
## Fixing Errors

**Note:** `get_string` is supposed to return address to the first byte of a string, but sometimes it may return `NULL` i.e. an invalid address that indicates something went wrong. 
- `char *a` is a string, but more precisely it is the address of the first byte of the string. 

- If something goes wrong when using `get_string` to return, it will return NULL or 0 (special address) where (address = 0) -- invalid address.

It turns out there's a library function in `string.h` written by others called `strcmp` which compares for us... to make this string better:
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    
    if (s == NULL) 
    // OR if (!s) {return 1}
    //If s is a valid address, but !s meaning NULL, return 1. Makes it more succinct. //Think of 0 as an invalid address not true or false. 
    
    {
        return 1; //something went wrong
    }
    
    char *t = get_string("t: ");
    if (t == NULL)
    {
        return 1; //avoiding SEGMENTATION FAULT
    }

    // Compare strings for equality
    if (strcmp(s, t) == 0) 
    //It is weird, it is opposite. strcmp does not return true or false. It returns 0 when strings are equal. Returns a positive value if s<t or negative value if s>t. It compares ASCII value
    //The return value for `strcmp` will be 0 if strings are equal. 
    {
        printf("same\n");
    }
    else
    {
        printf("different\n");
    }
    return 0; //If you dont return anything in main, it will secretly return int 0 
}
```
## Segmentation Faults
This means you _touched memory, you should not have_ or just **memory-related problems.**
- For example, if `get_string` doesn't return a valid address, we have to return an exit code of 1 to indicate some error has incurred i.e. _segmentation fault_, which means we tried to access memory we aren't able to (such as at the `NULL` address). 

Using 
```c
if (char *s == NULL)
{
    return 1;
}
```
will warn you of the problem. Add this so your program doesn't crash or segfault. 

Looking at another piece of code to copy a string:
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get a string
    string s = get_string("s: ");

    // Copy string's address
    string t = s; //Put memory address of 's' into 't'
    //

    // Capitalize first letter in string
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]); //Go to 0th character of t, change t. However, 's' is pointing to Brian so 's' is changed as well. 
    }

    // Print string twice
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
```
- Getting a string `s` and copying value of `s` into `t` then capitalizing first letter in `t`. 
        - However, I see both `s` and `t` are capitalized. 
        - Since, I set `s` and `t` to same values, they're actually pointers to the same character, so we capitalized the same character. 
        - 
        
![](https://cs50.harvard.edu/college/2018/fall/weeks/3/notes/pointers.png)
  
## Fixing this Problem 
Create the same string in a new chunk of memory i.e. get a bunch of memory then copy every character into this empty memory space. To actually make a copy of a string:

```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get a string
    char *s = get_string("s: ");
    if (!s)
    {
        return 1;
    }

    // Allocate memory for another string
    char *t = malloc((strlen(s) + 1) * sizeof(char));
    //char *t, tells comuter to give me chunk of memory in which I can store address of a character -- give me space for a pointer
    //malloc = memory allocation (give empty memory space to be filled)
    //How much memory? How many bytes? 
        
    if (!t)
    {
        return 1;
    }

    // Copy string into memory
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    // Capitalize first letter in copy
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // Print strings
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // Free memory
    free(t); //pass in variable, pointer that's storing the address of the chunk of memory that has been allocated
    return 0;
}
```
- Creating a new variable `t` of type `char *` with `char *t`. 
        - Want to point to a new chunk of memory that's large enough to store copy of stirng. 
        - With `malloc`, I can allocate some bytes of memory (not already used to store values), and pass in the number of bytes I'd like. 
                - Knowing the length of 's', I add 1 to that for the terminating null character, and multiply that by `sizeof(char)` (which gets us the number of bytes for each character) to be sure we have enough memory. 
                - `char *t = malloc(strlen(s)+1)*sizeof(char);

- Then, copying each character one at a time using array loops, I can now capitlize just the first letter of `t` using `i<=n` to go up one past `n` to ensure copying the terminating null character. 
        - Can use `strcpy` library function to copy a string without going through all this hassle but going through this code to demonstrate that you can't simply copy a string into another string and then do some operations to this new variable that stored the copy string. WHY? Because they're pointing to the same memory address!!

- Finally, call `free(t)` to tell computer that those bytes are no longer needed and useful and thus, those bytes in memory can be reused again. 
        - **Why do this?**
        - A _memory leak_ happens when we allocate more and more memory for our program to use, but we don't free that memory. Thus, gets slower and slower. 
        - **Malloc is opposite of free, use together.**

## Scan-Formatted Text
```c
#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");
    scanf("%i", &x); //INPUT THIS
    //&x is the special way of saying get the ADDRESS of x, so I can store the input into address memory.
    printf("x: %i\n", x);
}
```
`scanf` is a function that gets input from the user, according to a particular format. We pass in %i to indicate that we’re looking for an integer, and we use &x to get the address of x, so scanf can put the value into the right place in memory.

_However, if I try this with a string..._:

```c
//GETTING A STRING FROM USER INSTEAD OF INT CAN CREATE PROBLEMS

#include <stdio.h>

int main(void)
{
    char *s = NULL; //gives me space for the address of a character -- initialize to avoid segfaults
    printf("s: ");
    scanf("%s", s); //no need to use &s (scanf needs to be told where chunk of memory is to store inputted values)
    //however, s is already an address. S already has address
    
    //Recall, int x, the declaration of x variable (just an int). &x gets the address of that int. 
    //However, char *s is saying from initialization, get me the address of a char. 
    
    printf("s: %s\n", s);
}
```

- Output was NULL
- Since we didn't allocate memory for the actual bytes of the string, `scanf` had nowhere to store the input.
- **NEED TO ALLOCATE SOME NUMBER OF BYTES AS AN ARRAY OF CHARACTERS.**
- char *s is providing space of 1 byte (1 character), which is the size of a pointer.
        - There is not enough room to store a whole string into char *s. 
        - We didn't allocate enough space. 
        - We only allocated space for the address. 

To allocate space: 
```c
#include <stdio.h>
int main(void)
{
    //A string is just an array of characters. 
    //Create a string, but give me a chunk of memory.
    //I don't want the address of an character, I want the actual characters themselves. 
    
    char s[6]; //Space for 6 characters
    printf("s: ");
    printf("%s",s); //s is equivalent of being an address of a string

}
```

- Now I have 6 bytes in memory into which I can store input. 
- Notice that I can pass in `s` as an address, since **arrays can be treated like pointers to the first element in the array.**
- However, if I was to type in a longer string exceeding the memory I allocated, I evetually get a **_segmentation fault_** where I tried to access a segment of memory I couldn't or shouldn't. 
        - Telling computer to put user input at the memory location of s --in the array of characters
    
## Memory

To tie this all together, recall that we have physical chips of RAM in our computers, that store all the bytes we have. And each byte has an address. We can see this with below code:

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Print strings' addresses (the pointer)
    printf("s: %p\n", s);
    printf("t: %p\n", t);
}
```

- Here, we tell `printf  to treat `s` and `t` as pointers with `%p`, so we see addresses like `0x2331010` and `0x2331050.`
- Like binary and decimal, hexadecimals is a way to represent numbers and it has 16 possible values per digit (0-9 & A-F) -- it just happens **the addresses for `s` and `t` had no alphabetical characters. 
        - And a value in hexadecimal will conventially start with `0x` to indicate that.
        - Think of the **pointer output (addresses) as the numeric address in hexadecimal**
        
Let's say I want to swap values of 2 integers:
```c
#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
```
- There are no changes and NO swaps
        - It turns out `swap` function gets its own variables. When `a` and `b` are passed in, that are copies of `x` and `y` and so changing those values don't change `x` and `y` in the main function. 
        - **Bug: Passing in x and y in main, but a and b are copies of x and y since it does not change**
        - **Solution: Using ampersand to provide a map to the values so it can be changed.**
        
- By passing in address of `x` and `y`, the `swap` function can actually work:
```c
#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    
    swap(&x, &y); //typing in ampersand to get address, since swap functions are expecting 2 addresses/pointers NOT VALUES. 
    
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b) 
//speciying star in an argument to a function: you're expecting address of an int.
//2 pointers, 2 addresses of integers. 

{
    int tmp = *a; //You are storing addresses of a into tmp, BUT I WANT THE VALUES ( I DONT CARE ABOUT MEMORY).
    //*a gets values
    *a = *b; //
    *b = tmp;
}
```
**NOTE**:
- When using `*a` without mentioning data type, a star and variable name -- that star is **deference operator** where it will go to that address of a and get the value. 
- `int *a` means get the address of a, but `*a` means go to the address in memory and get me that value
- **The ampersand means what is the address of a variable, the star is the opposite -- when having the address, go to that address and get its value.  **


- **The address of `x` and `y` are passed in from `main` to `swap`, and using `*a` syntax to _follow (or deference) a pointer and get the value stored there_. 
        - Saving value to `tmp`, and then taking value at `b` and store that as _value_ of `a`. 
        - swap(&x,&y) stores the memory addresses (hexadecimals) of x and y into a,b arguments since swap function expects 2 pointers (int *a,*b)
        - Going into swap function, *a and *b (deference operators) GOES  TO THE address to obtain values
        - **By passing the addresses of `x` and `y` from `main` to `swap`, we could actually change the values of `x` and `y`**


Looking at buggy code:

```c
int main(void)
{
    int *x; //Declares 2 pointers (address of an int) and allocate memory for integer x but not y. So storing 13 into `*y` leads to segmentation faults. 
    
    int *y;

    x = malloc(sizeof(int));

    *x = 42; //Go to that memory address, and put 42 there. 
    *y = 13; //Address of y has NOT been allocated. 

    y = x; //If I set y to be same as x, pointing to same address, I can store value 13 to that location. 

    *y = 13;
}
```
- Code allocates 2 pointers, which can point to address of integers (int *x, *y) however, you're in pointing anything initially. 
- x = malloc(sizeof(int)); sets x to point to it, thus deference operator *x = 42 (doing a dereference on x stores x at address)

## Structs
- We can create variables of our own type with a concept called structs.
- For example, if we wanted to store both names and dorms of individual students, we might have arrays for each:
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Space for students
    int enrollment = get_int("Enrollment: ");
    string names[enrollment]; //array of strings
    string dorms[enrollment];

    // Prompt for students' names and dorms
    for (int i = 0; i < enrollment; i++)
    {
        names[i] = get_string("Name: ");
        dorms[i] = get_string("Dorm: ");
    }

    // Print students' names and dorms
    for (int i = 0; i < enrollment; i++)
    {
        printf("%s is in %s.\n", names[i], dorms[i]);
    }
}

```


But we might want to start having other pieces of data, and we have to make sure that all the arrays are the right length, and have the data for the same person at the same index. and so on. Instead, we can use structs, with a struct.h file containing:

```c
typedef struct
{
    char *name;
    char *dorm;
}
student;
```






















    
    
    
    
    
    
    
    
    
    

