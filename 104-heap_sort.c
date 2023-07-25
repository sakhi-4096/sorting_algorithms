#include "sort.h"

/**
 * sift_down - Perform sift-down operation on the heap to maintain
 *		the max-heap property
 *
 * @array: The array representing the heap
 * @size: Size of the heap
 * @index: Index of the element to be sifted down
 */
void sift_down(int *array, size_t size, size_t index)
{
	size_t root = index;
	size_t left_child = 2 * index + 1;
	size_t right_child = 2 * index + 2;
	size_t largest = root;
	int temp;

	if (left_child < size && array[left_child] > array[largest])
		largest = left_child;

	if (right_child < size && array[right_child] > array[largest])
		largest = right_child;

	if (largest != root)
	{
		temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;
		print_array(array, size); /* Print array after each swap */
		sift_down(array, size, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	/* Build the heap (rearrange the array) */
	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i);

	/* One by one extract elements from the heap */
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size); /* Print array after each swap */
		sift_down(array, i, 0);
	}
}
