# BinaryInsertionSort-Performance
 
- Insertion sort uses linear search to find the right place for the next item to insert. Would it
be faster to find the place using binary search (reduce number of comparisons)? We still
must shift 1 item at a time from the largest till the right place.

- Use binary search on the already sorted items to find the place where the new element
should go and then shift the exact number of items that need to be shifted and placing the
new item in its place. 

- The algorithm works the same, except that instead comparing and
shifting item by item, it will compare quickly using binary search but it will still shift one by
one till the right place (without comparison).

- Plot the performance of the algorithm against the original insertion sort.
