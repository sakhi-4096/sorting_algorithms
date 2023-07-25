#include "sort.h"

/**
 * swap - Swaps two elements in an array
 *
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lumoto partition scheme for Quick sort
 *
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in @array
 *
 * Return: The index of the pivot after partitioning
 */
size_t lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			/* Print the array after each swap */
			print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);
	/* Print array after each swap */
	print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_helper - Helper function for Quick sort
 *
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in @array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		size_t pivot_idx = lomuto_partition(array, low, high, size);

		if (pivot_idx > 0)
			quick_sort_helper(array, low, pivot_idx - 1, size);

		quick_sort_helper(array, pivot_idx + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
