#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h> //will be working with strings -- plaintexts. 

/*
Program: caesar
Purpose: Program enables to encrypt messages using caesar's cipher. At the time the user executes the program, the user should decide by providing a command line-argument, on what the key should be and the secret message they'll provide at runtime. 
Assumptions: Don't assume that the user's key is going to be a number, though assume if there is an number input than it is a positive integer. 

Arguments:
- First argument is plaintext
- Second argument is key (positive integer)

Pseudocode:
1. Check that program was run with one command-line argument
2. Iterate over the provided argument to make sure all characters are digits
3. Convert that command-line argument from a string to an int
4. Prompt user for plaintext
5. Iterate over each character of the plaintext:
    - If it is an uppercase letter, rotate it, preserving case, then print out the rotated character
    - If it is a lowercase letter, rotate it, preserving case, then print out the rotated character
    - If it is neither, print out the character as is
6. Print a newline



*/
        
    int k = atoi(argv[1]) % 26;
    string s = GetString();
    int len = strlen(s);
    
    for(int i = 0; i < len; i++)
        if(isalpha(s[i])) {
            int tmp = (int) s[i] + k;
            
            if(isupper(s[i])) {
                if(tmp > 65 + 25)
                    tmp -= 26;
            } else {
                if(tmp > 97 + 25)
                    tmp -= 26;
            }





int main(int argc, string argv[]) 
    //Arguments to the program takes input key and plaintext.
    //Type in command-line arguments where a string array is stored with argv[]
    //
{
    if (argc != 2) //If user does not provide exactly 2 arguments which I want the user to cooperate -- return 0
    {
        //counting command line
        printf("Usage: ./caesar key"); 
        return 1; //Program returning error 
    }
    else {
        prinf("Success!");
        return 0;
    }
    
    if (!isdigit(argv[1]))
    {
        // I want to make sure the second argument (key) is a number.
        // If the second argument is NOT a digit, return 1 (program error) 
        printf("Usage: ./caesar key"); 
        return 1; 
    }
}
