# C - Sorting Algorithms & Big O 
Is an algorithm that puts elements of a list into an order.

## Description
Sorting algorithms are a set of methods used to arrange elements in a specific order, such as ascending or descending. These sorting algorithms have different time and space complexities and are suitable for different scenarios. The choice of sorting algorithm depends on the size of the dataset, the nature of the data, and the specific requirements of the application. Some algorithms are more efficient for smaller datasets, while others excel at handling larger datasets efficiently. Big O notation provides an upper bound on the growth rate of an algorithm's time or space requirements as the input size increases.

## Features
 * Bubble Sort:
 	* Time Complexity: O(n^2)
 	* Bubble Sort is simple but inefficient, as it repeatedly compares and swaps adjacent elements. It is suitable for small datasets or educational purposes but becomes slow for larger datasets.
 * Selection Sort:
 	* Time Complexity: O(n^2)
 	* Selection Sort repeatedly selects the minimum element and places it at the beginning. Like Bubble Sort, it has a time complexity of O(n^2) and is inefficient for large datasets.
 * Insertion Sort:
 	* Time Complexity: O(n^2)
 	* Insertion Sort builds the final sorted array one element at a time. It performs well on small or nearly sorted datasets but is less efficient for large datasets.
 * Merge Sort:
 	* Time Complexity: O(n log n)
 	* Merge Sort is a divide-and-conquer algorithm that divides the array into two halves, recursively sorts them, and then merges the sorted halves. It has a time complexity of O(n log n) in all cases.
 * Quick Sort:
 	* Time Complexity: O(n log n) (average case), O(n^2) (worst case)
 	* Quick Sort uses a pivot to partition the array and then recursively sorts the subarrays. Its average-case time complexity is O(n log n), but it degrades to O(n^2) in the worst case when the pivot selection is unfavorable.
 * Heap Sort:
 	* Time Complexity: O(n log n)
 	* Heap Sort builds a binary heap from the array and repeatedly extracts the maximum element to create the sorted array. It has a time complexity of O(n log n) in all cases.
 * Shell Sort:
 	* Time Complexity: O(n log^2 n) (average case)
 	* Shell Sort is an optimized version of the Insertion Sort, using multiple gaps to sort subarrays. Its average-case time complexity varies depending on the chosen gap sequence.
 * Counting Sort:
 	* Time Complexity: O(n + k)
 	* Counting Sort is a non-comparison-based sorting algorithm that sorts integers in a limited range. It counts the occurrences of each element and places them in their correct positions, achieving linear time complexity.
 * Radix Sort:
 	* Time Complexity: O(d * (n + k))
 	* Radix Sort sorts integers by considering each digit's value. It is efficient for sorting integers with a fixed number of digits (d) and a limited range (k).

## Examples
```c
#include <stdio.h>

void bubble_sort(int arr[], int size) {
    int temp;
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                /* Swap elements at index j and j+1 */
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

## Usage
```
int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    bubble_sort(array, size);

    printf("\nSorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
    return 0;
}
```

## Credits


## Contact
 * [Sakhile Ndlazi](https://www.twitter.com/sakhilelindah)
