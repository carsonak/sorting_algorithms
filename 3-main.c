#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	/*int arr[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};*/
	int arr[] = {19, 48, 99, 71, 13, 87, 52, 96, 90, 99, 73, 86, 11, 12, 45, 7};
	size_t n = sizeof(arr) / sizeof(arr[0]);

	print_array(arr, n);
	printf("\n");
	quick_sort(arr, n);
	printf("\n");
	print_array(arr, n);
	return (0);
}
