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

