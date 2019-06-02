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

/*
 Program: Encrypts a plaintext message with a command-line keyword and the letters of the plaintext are encrypted (shifted by value) of sequence of keys in keyword, A/a = 0... Z/z = 25 shifts.
*/

bool is_valid_keyword(string keyword);


int main(int argc, string argv[])
{ 
    //Declaring variables
    string keyword = argv[1];
    int key_len = strlen(keyword);
    
    if (argc != 2 || !is_valid_keyword(keyword)) //not valid
    {
        printf("Usage: %s keyword\n",argv[0]); 
        return 1; //return error if command-line arguments !=2
    }
    else
    {
        for (int i = 0; i < key_len; i++)
        {
            keyword[i] = tolower(keyword[i]); 
            //making keyword lowercase to work with easier since shift A/a = 0; Z/z = 25
            //iterating through each character to ensure keyword is alphabetical       
        }
    }

    //Using a loop to iterate over each character of a string if I know its length    
    string plaintext = get_string("plaintext: ");
    int plaintext_length = strlen(plaintext); 
    
    //Iterate through plaintext characters "hello" plaintext[i] and encrypt plaintext[j] with key_values keyword[m]
    //Plaintext characters "Hello World!" -- keyword is lowercase characters --> need to set keyword to alphabetical index (a = 0 to z = 25)
    //Convert plaintext to ASCII (handling upper and lowercase) and shift by keyword[m] values
    //Convert encrypted message in ASCHII back to char when printing 
    printf("ciphertext: ");
    for (int i = 0, j = 0; i < plaintext_length; i++)
    {
        int tmp = (int) plaintext[i] + ((int) keyword[j] % 97); //alphabetical index;
        //ASCII character value shifted by k[j]%97
        
        if (j == key_len)
        {
            j = 0;
        }

        if (isalpha(plaintext[i]))
        {
            //If-else condition above ensures ASCII value in correct range after tmp is shifted by keyword[j]
            if (islower(plaintext[i]))
            {
                if (tmp > 97 + 25)
                {
                    tmp -= 26;
                }
            }
            else
            {
                if (tmp > 65 + 25)
                {
                    tmp -= 26;
                }
            }
            printf("%c", (char) tmp);
            j++;
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

bool is_valid_keyword(string keyword)
{
    //Declaring variables
    int key_len = strlen(keyword);
    
    for (int i = 0; i < key_len; i++)
    {
        if (!isalpha(keyword[i]))
        {
            return false; //return error if characters aren't alphabetical
        }
    }
    return true;
}


  
