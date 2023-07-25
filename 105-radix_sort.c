#include "sort.h"

/**
 * get_max - Get the maximum value in an array
 *
 * @array: The array to be processed
 * @size: Number of elements in @array
 *
 * Return: The maximum value in the array
 */
int get_max(const int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - Counting sort algorithm for a specific digit in
 *			radix sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @exp: The current digit position (1, 10, 100, etc.)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int index, i;
	int *output = malloc(sizeof(int) * size);
	size_t z;
	int count[10] = {0};

	if (output == NULL)
	{
		fprintf(stderr, "Memory allocation failed!\n");
		return;
	}

	/* Count the occurrences of each digit at the current position */
	for (z = 0; z < size; z++)
	{
		index = (array[z] / exp) % 10;
		count[index]++;
	}
	/* Calculate the cumulative counts */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array based on the cumulative counts */
	for (i = size - 1; i >= 0; i--)
	{
		index = (array[i] / exp) % 10;
		output[count[index] - 1] = array[i];
		count[index]--;
	}

	/* Copy the sorted output back to the original array */
	for (z = 0; z < size; z++)
		array[z] = output[z];
	/* Print array after each significant digit */
	print_array(array, size);

	free(output);
}

/**
 * radix_sort - LSD Radix Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	/* Perform counting sort for every significant digit */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
	}
}
