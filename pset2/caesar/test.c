#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h> 

int main(int argc, string argv[]) 
{
    int k = atoi(argv[1]) % 26; 
    string text = get_string("plaintext: ");
    int length = strlen(text);
    printf("ciphertext: ");
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i])) 
        {
            int tmp = (int) text[i] + k; //tmp = 123 = {
            
            if (isupper(text[i]))
            {
                if (tmp > 65 +25)
                {
                    tmp -=26;
                }
            }
            else
            {
                if (tmp > 97 + 25)
                {
                    tmp -=26;
                }
            }
            printf("%c",(char) tmp);
        }
    }
    printf("\n");
}


            /*
            if (isupper(text[i])) //if alphabetical letter is upper
            {
                if (tmp > 65 + 25) 
                {
                    tmp -= 26;
                }
                else
                {
                    if (tmp > 97 + 25) //tmp = 123 > 97+25
                    {
                        tmp -= 26; //tmp = 97 = 'a'
                    }
            }
                
            printf("%c", (char) tmp);         
        }
        else 
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
} 
*/
