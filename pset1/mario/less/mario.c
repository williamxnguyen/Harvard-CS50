#include <stdio.h>
#include <cs50.h>

/*
Height: 4
   #
  ##
 ###
####

Goal is to loop through each line. On each line begins with 1 hash. However, spaces decrease by 1 as has increases.
*/

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
        for (int j = 0; j < height-i-1; j++)
        {
            printf("."); //The number of dots decreases based on the index of the line. E.g. Height 5. At line 4, there is only 1 dot.
        }
        for (int k =0; k <= i; k++)
        {
            printf("#"); //This prints the number of hashes which is equal to i looping from 0 to height 
        }
        printf("\n"); //This goes to next line for each round of loop to create pyramid. 
    }
}

/* READING THE CODE: 
 * Initialize i=0. Is i< height=5? Yes. 
 * Initialize j=0. Is j < 5-0-1==4? Yes. Print 4 dots. 
 * Initialize k = 0. Is k <=0? Yes, print hash once. 
 * Go to new line. 
 * 
 * Increment i --> i=1. Is i==1<5? Yes
 * Increment j --> j=1. Is j==1<3? Yes. Print dots 3 times. 
 * k=1 (incrementation), is k<1? Print 2 hashes from k=0 to k=1. 
 * Skip to new line. 
*/
