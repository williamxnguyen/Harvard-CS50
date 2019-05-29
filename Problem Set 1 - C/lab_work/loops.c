/* Loops allow programs to execute lines of code repeatedly, saving you from needing to repeat lines of code. 

An infinite loop is when lines of code between curly braces will execute repeatedly from top to bottom, until and unless we break out of it (with break; statement) or otherwise kill our program. 

However, if while expression evaluates to true, all lines of code between curly braces will execute repeatedly in order from top to bottom until expression evaluates to false. Basically, while loop will continue until they are FALSE. 

Next loop is the do while loop, it will execute all lines of code once and then if the expression evaluates to true, it will go back and repeat process until expression evaluates to false. 
*/
do //do while loop is guaranteed to at least run one time
{
    //expression executed at least one 
}
while (x==5); //checking if condition is True, go back up and execute 'do' code. If while loop is false, move on. 

/* For loops are used to repeat the body of a loop a SPECIFIED number of times. The process undertaken at the bottom is: counter variable (i) is set -- boolean expression is checked. If true, body code executes, else body doesn't execute. Then, counter variable is incremented and then boolean expression is checked again....*/

for (int i = 0; i<10; i++)
{
    //expression
}

// Another way to look at for loops...
for (start; expr; increment)
{
    // Statement in start are executed. 
    // Expression is checked. Body of loop executes if expression evaluates to true. 
    // Statement in increment are executed, then expression is checked again.
}


//When to use loops?
// Use WHILE loops when you want a loop to repeat an unknown number of times and possibly not at all. 
// Use do while loops when you want a loop to repeat an unknown number of times but at least once, 
// Use for loops to repeat a discrete number of times...
 



