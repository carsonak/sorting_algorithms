#include "sort.h"

/**
 * bubble_sort - bubble sort pushes the largest element to the end of the array
 * @array: array to be sorted
 * @size: length of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t g = 1, max = size, new_max = 0;
	int b = 0;

	while (max > 1)
	{
		for (g = 1; g < max; g++)
		{
			if (array[g - 1] > array[g])
			{
				b = array[g - 1];
				array[g - 1] = array[g];
				array[g] = b;
				new_max = g;
				print_array(array, size);
			}
		}

		max = new_max;
	}
}
