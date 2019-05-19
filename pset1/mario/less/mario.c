#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: \n");
    }
    while (height<=0 || height >=20); //if number is negative, get user input again. Code will move on when while loop evaluates to false. If height is less than 0 (while =true), get height again
    
    for (int i = 0; i < height; i++)
    {
        //for (int j = 0; j < height -i; j++)
        //{
            //printf(" ");
        //}
        for (int k =0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
