/*
# Functions
    
**Practice Problem**: Declare and write a function called `valid_triangle` that takes three real numbers representing the lengths of the three sides of a triangle as its arguments and outputs either _true_ or _false_, depending on whether those 3 lengths are capable of making a triangle. 
    - A triangle may only have sides with positive lengths 
    - The sum of the lengths of any two sides of the triangle must be greater than the length of the third side. 
*/

#include <stdio.h>
#include <string.h>
#include <cs50.h>

bool valid_triangle(int a, int b, int c);
   
int main(void)
{
    bool answer = valid_triangle(1,2,3);
    printf("The answer is: %s\n", answer ? "true":"false");
}


bool valid_triangle(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }
    else
    {
        //if sum of lengths of any two sides > length of third side thus a triangle
        if ((a+b>c) || (a+c>b) || (b+c>a))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
