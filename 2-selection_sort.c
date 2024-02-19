#include "sort.h"

/**
 * selection_sort - Selection sort
 * @array: the array to be sorted
 * @size: size of the array to be sorted
 *
 * Description: Selection sort tracks a boundary in the list where one side
 * contains the unsorted list and the other the sorted list. (The sorted side
 * usually begins empty while the unsorted side is full).
 * The smallest/largest item will be poped from the unsorted array and
 * appended to the end of the sorted array till all items are sorted.
 */
void selection_sort(int *array, size_t size)
{
	size_t g = 0, h = 0, s_i = 0;
	int smallest = 0;

	if (!array || !size)
		return;

	for (g = 0; g < size - 1; g++)
	{
		s_i = g;
		smallest = array[s_i];
		for (h = g + 1; h < size; h++)
		{
			if (array[h] < smallest)
			{
				s_i = h;
				smallest = array[s_i];
			}
		}

		if (s_i > g)
		{
			array[s_i] = array[g];
			array[g] = smallest;
			print_array(array, size);
		}
	}
}
