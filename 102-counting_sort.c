#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *		using Counting Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max_num, j, *counts, num, z;

	if (array == NULL || size < 2)
		return;

	max_num = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
	}

	counts = malloc(sizeof(int) * (max_num + 1));
	if (counts == NULL)
		return;

	/* Initialize count array with zeros */
	for (j = 0; j <= max_num; j++)
		counts[j] = 0;

	/* Count occurrences of each element */
	for (i = 0; i < size; i++)
	{
		num = array[i];
		counts[num]++;
	}

	print_array(counts, max_num + 1);

	j = 0;
	/* Update array with sorted elements */
	for (z = 0; z <= max_num; z++)
	{
		while (counts[z] > 0)
		{
			array[j] = z;
			j++;
			counts[z]--;
		}
	}

	free(counts);
}
