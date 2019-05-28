#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h> 

/*
Writing a program called `vigenere` that enables you to encrypt messages using Vigenère’s cipher. 

At the time the user executes the program, they should decide, by providing a command-line argument, on what the keyword should be for the secret message they’ll provide at runtime.

Input:
- Upon running command line, takes one keyword argument which is (keyword to encrypt). 
- Keyword must be fully alphabetic
- User must provide at least 1 keyboard, not too many and must be not at all. 

One difference between Caesar’s and Vigenère’s ciphers is that the key for Vigenère’s cipher is a **series of letters, rather than a number.**
*/

//User provided single character keywords -- convert that character into the correct shift value
//Input single character and output integer shift value for that character
int shift(char c); //declaring prototype

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s keyword\n",argv[0]);
        return 1;
    }
    else
    {
        int key = shift(argv[1][0]); //argv[1][0] is the first character of that string
        printf("%i\n",key)
    }
    
    int len = strlen(argv[1]); //Using a loop to iterate over each character of a string if I know its length
    for (int i = 0; i < len; i++)
    {
        //iterating through each character to ensure keyword is alphabetical
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: %s keyword\n",argv[0]);
            return 1;
        }
    }
}

int shift(char c) 
{
    //TODO: Convert character to positional integer value (A/a = 0, Z/z = 25)
    //The ASCII value of A is 65. The ASCII value of a is 97.
    //The ASCII value of B is 66. The ASCII value of b is 98. See a potential pattern emerging?
    
    
}

















