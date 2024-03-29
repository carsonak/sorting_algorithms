#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void free_dlist(listint_t *head);

void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);
size_t lomuto_partition(int *array, size_t bot, size_t top, size_t size);
void range_manager(int *array, size_t bot, size_t top, size_t size);

void insertion_sort_list(listint_t **list);
int swap_list(listint_t **n_a, listint_t **n_b);
void sep_nodes(listint_t **n_a, listint_t **n_b, listint_t *separator);

#endif /*_SORT_H_*/
