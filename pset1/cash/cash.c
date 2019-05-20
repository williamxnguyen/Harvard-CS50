#include <stdio.h>
#include <cs50.h>
#include <math.h>

/*
 Program asks **_asks the user how much change is owed and then prints the minimum number of coins with which that change can be made._**
 */

/*PSEUDOCODE:
1. Prompt user for an amount of change owed back.
    - Make sure to accept values that make sense. 
    - Make sure the do-while(condition) accepts only float values. 
1B. Convert dollars to cent since floats have floating point inprecision -- convert into integers. 

2. Always use largest coin possible (25 cents, 10 cents, 5 cents, and 1 cent)
3. Keep track of coins used
4. Print final number of coins


- get amount in dollars
- convert to cents
- while(quarters can be used) increase count and decrease amount by quarter
- while (10 cents can be used), increase count and decrease amount by dime .....

- print number of counts us

I will approach this problem by using modulo math which returns the remainder after divison. 
*/

int main(void)
{
    //declare variables
    float change;
    int number_of_coins = 0; //declaring initial amount of coin counter
    int quarter = 25; int dime = 10; int nickel = 5; int penny = 1;
    int cents;
    
    do
    {
        change = get_float("How much change owed: \n");
        printf("Total owing %.2f\n",change);
    }
    while (change <= 0); //user input will be reprompted if negative
    
    cents = round(change*100); //converted inputted dollar change into cents. 
    printf("Cents.. %i\n",cents);
    
    while (cents >= quarter)
    {
        cents -= quarter;
        number_of_coins++;
    }
    
    while (cents >= dime)
    {
        cents -= dime;
        number_of_coins++;
    }
    
    while (cents >= nickel)
    {
        cents -= nickel;
        number_of_coins++;
    }
    
    while (cents >= penny)
    {
        cents -= penny;
        number_of_coins++;
    }
    
    printf("The number of coins needed is: %i \n",number_of_coins);
}
