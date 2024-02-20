#include "sort.h"

/**
 * quick_sort - Quick sort with Lomuto partitioning scheme
 * @array: the array to be sorted
 * @size: length of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size)
		range_manager(array, 0, size, size);
}

/**
 * range_manager - recursively partitions an array in two sections with
 * values either greater or less than the middle value
 * @array: the array to be partitioned
 * @bot: the starting index of the range
 * @top: size of the range
 * @size: size of the whole array
 */
void range_manager(int *array, size_t bot, size_t top, size_t size)
{
	size_t piv_i = 0;

	/*Base case: partition should have atleast 2 elements*/
	if (!array || !size || top > size || (top - bot) < 2)
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
 * pivot which partitions the range into two sections. One section will
 * contain values greater than the pivot and the other section the rest.
 * Once all the items have been sorted, the pivot is then inserted at the
 * border of the two sections.
 * The index of the pivot is then rturned
 *
 * Return: index of the pivot
 */
size_t lomuto_partition(int *array, size_t bot, size_t top, size_t size)
{
	/*g searches the upper section*/
	size_t g = bot + 1;
	/*piv_i tracks the border between the sections*/
	size_t piv_i = bot;
	int pivot = array[top - 1], tmp = 0;

	if (!array || !size || top > size)
		return (0);

	while (g < top - 1)
	{
		/*Swapping items less than pivot into the lower section*/
		/*Swapping will only occur if necessary*/
		if (array[g] <= pivot && array[piv_i] > pivot)
		{
			tmp = array[g];
			array[g] = array[piv_i];
			array[piv_i] = tmp;
			print_array(array, size);
		}

		/*Ensure a items <= pivot are always in the lower section*/
		if (array[piv_i] <= pivot)
			piv_i++;

		g++;
	}

	/*Placing pivot at the border*/
	if (array[piv_i] > pivot)
	{
		array[top - 1] = array[piv_i];
		array[piv_i] = pivot;
		print_array(array, size);
	}
	else
		piv_i = g;

	return (piv_i);
}
