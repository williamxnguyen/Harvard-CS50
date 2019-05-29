/* Conditional expressions allow your programs to make decisions and take different forks in the road depending on the values of variables or user input. These conditional expressions are also known as conditional branches*/

#include <stdio.h> 
#include <cs50.h>

/* C's switch() statement is a conditional statement that permits enumeration of discrete cases, instead of relying on Boolean expressions. It's import to break; between each case, or I will make the mistake of "falling through." each case. */

int x = GetInt();
switch(x) 
{
    case 1:
        printf('One! \n');
        break;
    case 2:
        printf('Two \n');
        break;
    default:
        printf('Sorry!\n');
}

//The code below is the same as ... 
int x = GetInt();
if (x == 5)
{
    x = 5; // assigning x to 5
}
else
{
    x = 6;
}
// The above code is the same as below 
int x = (x == 5) ? 5 : 6; //used to replace simple if-else to make code look fancy
/*The ternary operator (?:) is just a trick but is useful for writing trivially short condition branches. Use it for small conditional branches. The value after the question mark is what x would be if the expression is true. The value after the semi colon is x is the expression is evaluated false. */

