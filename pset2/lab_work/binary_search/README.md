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
