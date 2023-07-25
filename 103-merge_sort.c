#include "sort.h"

/**
 * merge - Merges two sorted subarrays into a single sorted array
 *
 * @array: The original array
 * @size: Total size of the array
 * @left: The left subarray to be merged
 * @left_size: Size of the left subarray
 * @right: The right subarray to be merged
 * @right_size: Size of the right subarray
 */
void merge(int *array, size_t size, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *temp = malloc(sizeof(int) * size);

    if (temp == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            temp[k++] = left[i++];
        else
            temp[k++] = right[j++];
    }

    while (i < left_size)
        temp[k++] = left[i++];

    while (j < right_size)
        temp[k++] = right[j++];

    for (i = 0; i < size; i++)
        array[i] = temp[i];

    free(temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    size_t mid = size / 2;
    size_t left_size = mid;
    size_t right_size = size - mid;

    int *left = array;
    int *right = array + mid;

    merge_sort(left, left_size);
    merge_sort(right, right_size);

    merge(array, size, left, left_size, right, right_size);
}
