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
        return 1; //return error if command-line arguments !=2
    }
    /*else
    {
        int key = shift(argv[1][0]); //argv[1][0] is the first character of that string
        printf("%i\n",key)
    }*/
    
    //Using a loop to iterate over each character of a string if I know its length
    string keyword = argv[1];
    int key_len = strlen(argv[1]);
    string plaintext = get_string("plaintext: ");
    int plaintext_length = strlen(plaintext); 
    
    for (int i = 0; i < key_len; i++)
    {
        keyword[i] = tolower(keyword[i]); //making keyword lowercase to work with easier since shift A/a = 0; Z/z = 25
        //iterating through each character to ensure keyword is alphabetical
        if (!isalpha(keyword[i]))
        {
            printf("Usage: %s keyword\n",argv[0]);
            return 1; //return error if characters aren't alphabetical
        }
    }
    

    //Iterate through plaintext characters "hello" plaintext[i] and encrypt plaintext[j] with key_values keyword[m]
    //Plaintext characters "Hello World!" -- keyword is lowercase characters --> need to set keyword to alphabetical index (a = 0 to z = 25)
    //Convert plaintext to ASCII (handling upper and lowercase) and shift by keyword[m] values
    //Convert encrypted message in ASCHII back to char when printing 
    
    
    printf("ciphertext: ");
    for (int i = 0; i < plaintext_length; i++)
    {
        int tmp = (int) plaintext[i]; //ASCII character value
        
        for (int j = 0; j < key_len; j++)
        {
            int k = (int) keyword[j] % 97; //Turning keyword (for e.g. KEY) into lower and into alphabetical index
            tmp += k; //Shifting plaintext ASCII value by k
            
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
            }
            else
            {
                printf("%c", plaintext[i]);
            }
            }
        printf("\n");
    }
}



/*    
}
int shift(char c) 
{
    //TODO: Convert character to positional integer value (A/a = 0, Z/z = 25)
    //The ASCII value of A is 65. The ASCII value of a is 97.
    //The ASCII value of B is 66. The ASCII value of b is 98. See a potential pattern emerging?
    //ci = (pi + kj) % 26

    
    
}

    for (int j = 0, m = 0; j < plainlen && m <= keylen; j++)
    {
        if (isalpha(plain[j]))
        {
            // Sets index for keyword m to 0, starts encryption back at beginning of keyword
            if (m == keylen)
            {
                m = 0;
            }
            if (isupper(plain[j]))
            {
                if (isupper(k[m]))
                {
                    x = plain[j] - 'A';
                    y = (k[m] - 'A');
                    z = (x + y) % 26;
                    printf("%c", z + 'A');
                    m++;
                }
                else
                {
                    x = plain[j] - 'A';
                    y = (k[m] - 'a');
                    z = (x + y) % 26;
                    printf("%c", z + 'A');
                    m++;
                }

            }
            else
            {
                if (isupper(k[m]))
                {
                    x = plain[j] - 'a';
                    y = (k[m] - 'A');
                    z = (x + y) % 26;
                    printf("%c", z + 'a');
                    m++;
                }
                else
                {
                    x = plain[j] - 'a';
                    y = (k[m] - 'a');
                    z = (x + y) % 26;
                    printf("%c", z + 'a');
                    m++;
                }

            }
        }
        else
        {
            printf("%c", plain[j]);
        }
    }
    printf("\n");
    return 0;
}
*/
