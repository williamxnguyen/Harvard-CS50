// Data Types and Variables
#include <stdio.h>
#include <cs50.h>
// In C, need to specify the data type of every variable. 

/* Int data type stores integers and it always takes up 4 bytes of memory (32 bits). This means, the range of values they can store is necessarily limited to 32 bits worth of information.

An unsigned integer is a qualifier where it modifies the data type integer slightly. It effectively DOUBLES the positive range of variables of that type (in this case integer) at the cost of disallowing any negative values. Only use unsigned int if you know the value will never be negative. The range is 0 to 2^32 -- no negative values. 

Char data type is used for variables that stores single characters and take up 1 byte of memory (8 bits). 

Floating data types are used for variables that will store floating-point values also known as real values. You can represent pi as a float. However, if the decimal gets longer and longer -- c won't be as precise with the decimal part and that's the limitation. Float has a precision problem, it only has 32 bits to work so it can be an approximate with long decimal part. 

Double data type is used for variables that will store floating point values. This is different from floats since doubles are double precision. They take up 8 bytes of memory (64 bits) to specify much more precis real numbers. If you're working in a place with long decimal and needs real precision -- use double data type to provide more precision. 

void is a TYPE, not a data type. Functions can have a void return type -- it doesn't return a value. For example, printf is a void function (void return type) since it only prints something to the screen and returns nothing to the screen. 
The parameter list of a function can also be void -- it simply means function takes no parameters. You can specify a function that doesn't any arguments by adding void parameters. */
int main(void) {
    //expression
}
//Void serves as a placeholder for 'nothing'. No return value, no parameters -- nothing. 

// Creating a variable is done by giving it a type and a name. 
char letter; 
//Creating multiple variables of same time by... 
int height, width; 
float sqrt2, pi; 

//After a variable has been declared, it's no longer necessary to specify that variable's type. 
int number; //declaration
number = 17; //assignment
char letter;
letter = 'H';

//Simultaneously declaring and setting the value of a variable (initializing)
int number = 17; //initialization















