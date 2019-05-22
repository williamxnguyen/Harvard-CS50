# Arrays

- Arrays are fundamental **data structures**, and they're extremely useful!
- I could use arrays to hold values of the same type at the contiguous memory locations. 
- An array:
        - is a blog of contiguus space in memory..
        - which has been partitioned into small, identically-sized blocks of space called **elements.**
        - each of which can store a certain amount of **data**.
        - _all of the same data type_ such as **int** or **char**. 
        - I can access element by an index directly. 
- In C, the elements of an array are idnexed starting from 0. 
        - If an array consists of n elements, the first element is located at index 0. **_The last element is located at index (n-1)._**
        

## Array Declaration

> type name[size];
- The type is what kind of variable each element of the array will be. 
- The name is what you want to call your array
- The size is how many elements I would like my array to contain. 

- When declaring and intializing an array simultaneously, there is special synthax that may be used to fill up the array with its starting values. 

```c
//instantiation syntax//
bool truthtable[3] = {false, true, true}; //You can omit the size of array (3) to create an array -- no need to indicate the size of array beforehand.
//C compiler knows how big the array is based on the values on the right of equal sign. 

//individual element syntax
bool truthtable[3];
truthtable[0] = false;
truthtable[1] = true;
truthtable[2] = true;
```
## Dimensions
Arrays can consist of more than a single dimension. I can have as many size specifiers as I wish. 
> bool battleship[10][10];

I can choose to think of this as either a 10x10 grid of cells. 
        - In memory, it's really just a 100-element one-dimensional array.
        - Multi-dimensional arrays are great abstractions to help visualize game boards or other complex representations.
        
While, I can treat individual elements of arrays as variales, I cannot treat entire arrays themselves as variables.

For example, assign one array to another using the assignment operator. That's not legal C. 

Instead, I must use a for loop to copy over the elements one at a time. 

```c
int foo[5] = {1,2,3,4,5};
int bar[5];

//copying contents inside foo into bar
for (int j =0;j<5;j++)
{
    bar[j] = foo[j];
}
```
## Passed by Reference 
- Recall that most variables in C are **passed by value** in function calls. 
- Arrays do not follow this rule. Rather, they are **passed by reference**. The callee receives the actual array, _not_ a copy of it. 

- Sample array code:
```c
/*
Outputs: 10,22 (a,b[0]) -- due to passing arrays by reference and passing variables by values. 
*/

void set_array(int array[4]); //function declarations - takes array of 4 integer inputs -- no output (void)
void set_int(int x); //set_int takes a single integer as its input -- no output (void)

int main(void)
{
    int a = 10;
    int b[4] = {0,1,2,3};
    set_int(a); // call
    set_array(b); // call
    
    printf("%d %d\n",a,b[0]);
}

void set_array(int array[4])
{
    array[0] = 22;
}
void set_int(int x)
{
    x = 22;
}

```








