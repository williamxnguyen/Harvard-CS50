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

                


