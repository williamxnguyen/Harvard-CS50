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

int main(int argc, string argv[]) //argv[] is a pointer array which points to each argument passed in command line
{
    //argc refers to number of arguments passed
    //Arguments to the program takes input key and plaintext.
    //Type in command-line arguments where a string array is stored with argv[]
    if (argc != 2) //Checking that program was run with one command line argument (argc=2)
    {
        printf("Usage: %s key \n", argv[0]); //User did not input exactly one command line from command line at runtime. 
        return 1; //Program returning error (return from main value 1 to signify error immediately). 
    }
    else 
    {
        printf("Successful number of inputs added!\n");
    }
    
    /*Now I want to iterate over provided argument to make sure all characters are digits because this is a key. 
     * And a key is a positive integer. 
     */

    
    int len = strlen(argv[1]); //determining length of argument passed through command line
    //Since I know the length I can loop to iterate over each character of a string (argv[1]) to validate the key
    
    for (int i = 0; i < len; i++) //looping through each string character of passed argument
    {
        if (!isdigit(argv[1][i])) 
            //determining whether each it is a digit
            //isdigit() takes single integer argument and returns value of type int
            //even though isdigit() takes integer as an argument, character is passed to function and internally, 
            //Then, character is converted to ASCII value for check/ 
            
            // I want to ensure second argument (key is a number). 
        {
             printf("Usage: .%s key \n",argv[0]);
             return 1; //return 1 (program error) if one of the loop is not a digit. 
        }
    }   
    //1. If above string consists soley of digit characters -- 
    //I will convert STRING (argv[1]) to an ACTUAL NUMBER (argv is array of strings, even if strings happen to look like numbers)
    
    //2. Prit out the integer using placeholder -- however argv is an array of string so use **atoi function** to convert string that looks like a number into that number
    
    //Important Note: atoi function converts str into an integer.
    int k = atoi(argv[1]) % 26; //Converting argv[1] (string, even if it is a string-number) into an integer
    //I did %26 (remainder when dividing by 26) to make sure the key-rotational value is within len(alphabet)
    //E.g. k = 3%26 or 0%26 or 25%26 or 26%26 is respectively (3,0,25,0)
    //Explaining why I did further %26 -- Think a as 0, b as 1, ... and z as 25. 
    //I want to use a key of 3, so I rotate my plaintext and add by 3.
    //Explanation: if k>26, store division remainder instead.     
    
    //ENCRYPTION 
    string text = get_string("plaintext: "); //Prompt user for secret message to shift all of its characters by k
    int length = strlen(text);
    
    printf("ciphertext: ");
    for (int i = 0; i < length; i++)
    {
        int tmp = (int) text[i] + k; //encrypted ASCII value
        if (isalpha(text[i])) 
            //I want to ensure encryption ignores spaces and punctuation so it isn't "shifted by cipher"
            //isalpha() checks whether character text[i] (type char) is an alphabet (a-z, A-Z) or not
            //if !isalpha(), it returns 0.
            //Even though, isalpha() takes integer argument --> character is passed through and converted into ASCII integer 
        {
            //Unrelated note: printf("%i \n",text[i]); //Printings out ASCII value of plaintext integers
            //int tmp = (int) text[i] + k; //Getting the ASCII value of ciphertext by using (int)
            //Iterating over each character in plaintext and shift characters by certain k value
            
            if (islower(text[i])) 
            {
                if (tmp > 97 + 25) 
                    //ensures that ASCII value of cipher text (plaintext rotated by k) is not more than ASCII VALUE = 65 + 25
                    //what if lower-case alphabetical plain text was x,y,z but now encrypted ascii is > 65+25
                    //thus, need to -26 to do a loop back .. x,y,z,a,b,c not x,y,z,{,|,}                {
                    tmp -= 26;
                    //If my upper character is "Z" (text[i]) and k =1. If I wanted the ASCII value of Z (90) and shift this by k
                    //I would expect my encrypted value to be A after shifting Z by 1 (making a loop back to the alphabetical order)
                    
                    //However, encrypted ASCII value would now be 91 after shifting "Z" (90) by k=1 
                    //When I convert this (int) tmp back to char, it would give me "["
                    //This is not what I want. 
                    //Thus, I have to -26 so make a loop back, thus my ASCII encrypted value would be 65 (A)
                }
                else
                    //If my upper character is "Z" = (text[i]) and key =1. 
                    //If I wanted the ASCII value of Z, it would be 90. To encrypt, I shift this by k%26 value
      
                    //I would expect my encrypted value to be A after shifting Z by 1 (making a loop back to the alphabetical order)                    
                    //However, encrypted ASCII value would now be 91 after shifting "Z" (90) by k=1 
                    //When I convert this (int) tmp back to char, it would give me "["
                    //This is not what I want. 
                    //Thus, I have to -26 so make a loop back, thus my ASCII encrypted value would be 65 (A)
                {
                    if (tmp > 65 + 25)
                    {
                        tmp -= 26;
                    }
                }
            //printf("%c",(text[i]+k)); OR
            printf("%c", (char) tmp); //cipher text            
        }
        else 
            //IF NOT ALPHABETICAL
            //I want to shift ONLY letters and nothing else (e.g. punctuation, space etc.)  
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    //return 0; //exit main program for successful run
}
 
