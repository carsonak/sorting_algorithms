#include "sort.h"

/**
 * quick_sort - Quick sort
 * @array: the array to be sorted
 * @size: length of the array
 */
void quick_sort(int *array, size_t size)
{
	range_manager(array, 0, size, size);
}

/**
 * range_manager - recursively partitions an array into smaller ranges till
 * they can be sorted trivially.
 * @array: the array to be partitioned
 * @bot: the starting index of the range
 * @top: size of the range
 * @size: size of the whole array
 */
void range_manager(int *array, size_t bot, size_t top, size_t size)
{
	size_t piv_i = 0;

	/*Base case: partition should have atleast 2 elements*/
	if ((top - bot) < 2)
		return;

	piv_i = lomuto_partition(array, bot, top, size);
	/*Left partition*/
	range_manager(array, bot, piv_i, size);
	/*Right partition*/
	range_manager(array, piv_i + 1, top, size);
}

/**
 * lomuto_partition - Lomuto partitioning scheme
 * @array: the array to be partitioned
 * @bot: the starting index of the range
 * @top: size of the range
 * @size: size of the whole array
 *
 * Description: This function will select the last index in the range as the
 * pivot then partition the range into two sections. One section will contain
 * values greater than the pivot and the other section the rest. The pivot is
 * then inserted in between these two sections.
 * The index of the pivot is then rturned
 *
 * Return: index of the pivot
 */
size_t lomuto_partition(int *array, size_t bot, size_t top, size_t size)
{
	size_t g = bot + 1, piv_i = bot;
	int pivot = array[top - 1], tmp = 0;

	while (g < top - 1)
	{
		if (pivot >= array[g])
		{
			if (pivot != array[g])
			{
				tmp = array[g];
				array[g] = array[piv_i];
				array[piv_i] = tmp;
				print_array(array, size);
			}

			piv_i++;
		}

		g++;
	}

	if (array[piv_i] > pivot)
	{
		array[top - 1] = array[piv_i];
		array[piv_i] = pivot;
	}

	return (piv_i);
}
