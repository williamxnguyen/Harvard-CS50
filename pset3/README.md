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

It turns out there's a library function in `string.h` written by others called `strcmp` which compares for us... to make this string better:
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Compare strings for equality
    if (strcmp(s, t) == 0)
    {
        printf("same\n");
    }
    else
    {
        printf("different\n");
    }
}
```
    - The return value for `strcmp` will be 0 if strings are equal. 
    
**Note:** `get_string` is supposed to return address to the first byte of a string, but sometimes it may return `NULL` i.e. an invalid address that indicates something went wrong. 

    
    
    
    
    
    
    
    
    
    
    
    
    
    

