#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *		Shell sort with Knuth sequence
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;

	if (array == NULL || size < 2)
		return;

	/* Generate the Knuth sequence: n+1 = n * 3 + 1 */
	while (gap < size)
		gap = gap * 3 + 1;
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		size_t i, j;
		int temp;

		/* Perform insertion sort on subarrays with given gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}

		/* Print the array each time we decrease the interval */
		print_array(array, size);

		/* Update the gap according to the Knuth sequence */
		gap = (gap - 1) / 3;
	}
}
