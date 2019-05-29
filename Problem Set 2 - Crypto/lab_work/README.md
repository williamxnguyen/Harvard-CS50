# Algorithms Summary
## Selection Sort
**Concept**: Find the **smallest** unsorted element in an array and swap it with the first unsorted element of that array. The worst-case run time is **_n^2_**.

## Bubble Sort
**Concept:** It swaps the **adjacent pairs** of elements if they are out of order, effectively 'bubbling' larger elements to the right and smaller ones to the left. 

## Insertion Sort
**Concept:** The key concept is **shifting**. This algorithm steps once through the array from left-to-right, shifting elements as necessary to insert each element into its correct place. 

## Merge Sort
**Concept:** The key idea is _split and merge_. **Split** the full array into subarrays by half and half ... until I have a set of n ONE element arrays. Then **merge** those subarrays back together in the correct order. The best and worst case run time of merge sort algorithms is nlogn. Since, there are n elements but this recombining process takes logn steps to get back to a full array. 

## Linear Search
**Concept:** This algoritm **iterates** across the array from left-to-right, trying to find the target element. The worst case run time is O(n) -- it might take us iterating across every single element to find target element. In the best case, we find it immediately with a best-case run time for linear search algorithm is omega(1).

## Binary Search
**Concept:** Given a _sorted array_ (necessary pre-requisite), **divide and conquer** by systematically eliminating half of the remaining elements in the search for target element i.e. eliminating half of the elements each time you proceed through. The worst-case run time is thus O(logn) which is much better than O(n). The best case run time is omega(1) since I might find it immediately the first time I make a division. 

It is important to note, since binary search algorithms are fast -- I have to go through the work of sorting the array first which is less effective depending on the size. 

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

# Binary Search
It is an algorithm used to find an element in array. 
- In binary search, the idea of the algorithm is to divide and conquer, reducing the search area by half each time, trying to find a target number. 
        - In order to leverage this power however, our array must **first be sorted, else we cannot make assumptions about the array's contents**. 
        - It reduces the size of the search area by half each time to find target number IF array is sorted. 
        
_In pseudocode:_
- Repeat until the (sub)array is size 0:
        - Calculate the middle point of current subarray. 
        - If target is at the middle, stop. 
        - Otherwise, if target is less than what's at the middle, repeat, changing the end point to be just to the left of the mid point.
        - Conversly, the target is greater than mid point, repeat, changing the end point to just to the right of midpoint. 


# Bubble Sort
## Concept
Bubble sort is an algorithm used to sort a set of elements. 
- In bubble sort, the idea of the algorithm is to move higher valued elements towards the right and lower value elements generally towards the left. 

**_Pseudocode:_**
- Set swap counter to a non-zero value
- Repeat until swap counter is 0:
        - Reset swap counter to 0. 
        - Look at adjacent pair.
                - If two adjacent elements aren't in order, swap them and add 1 to the swap counter.
                - This effectively moves lower values to left and higher values to the right. 
                
                
- **Worst-case scenario:** The array is in reverse order; we have to bubble each of the n elements all the way across the array, and since I can only fully bubble one element into its position per pass, I must do this n times. (n^2)

- **Best-case scenario:** The array is perfectly sorted already, and I make no swaps on the first pass i.e. looking at each elements once (n) --> this is better than selection sort. 

# Linux Command Line
- CS50 IDE is a cloud-based machine running Ubuntu, one of the many flavors of the Linux OS. 
- Many modern linux distributions have graphial user interfaces (GUI) to allow easy mouse-based navigation. 
- Still, as a programmer you'll likely be using terminal window frequently and you can do many of the same tasks with keyboard commands. 

## Linux Commands
Some of the most important keyboard-based commands for working within the IDE or any UNIX-based system:
- `ls <directory>`: This command accesses the contents of the current directory.
- `cd <directory>`: Short for "change directory", this command changes your directory to **<directory>**, which I can specify on my workspace or operating system. The shorthand name for the parent directory of current directory is **..**
- `pwd`: If curious about the current directory that I'm working on, I can type pwd (present working directory). 
- `mkdir <directory>`: Short for "make directory", this command will create a new subdirectory called **<directory>** located in the current directory.
- `cp <source> <destination>`: Short for "copy", this command will allow you to create a duplicate of the file you specify as **<source>**, which it will save in **<destination>**. 
        - If you wish to copy entire directories, modify the command to **cp -r <source directory> <destination_directory>**. The "-r" stands for _recursive_, and tells cp to dive down into the directory and copy everything inside of it (including subdirectories it may contain.)
        - The **-r** tells the cp command to recursively dive down into the directory and make a copy of everything. 
- `rm <file>`: Comamnd is short for "remove". 
        - To delete entire directories, just use the **-r** flag. `rm -r <directory>`. 
- `mv <source> <destination>`: short for "move", this command effectively rename a file, moving it from <source> to <desintation>. 
        - Basically, this is used to rename files from <source> to another name <destination>
                
# Debugging






