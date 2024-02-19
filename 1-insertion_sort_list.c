#include "sort.h"

/**
 * insertion_sort_list - insertion sort
 * @list: linked list
 *
 * Description: Insertion sort tracks a boundary in the list where one side
 * contains the unsorted list and the other th sorted list. (The sorted side
 * usually begins empty while the unsorted side is full).
 * Items from the unsorted side will be inserted into the correct position in
 * the sorted side.
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *to = NULL, *fro = NULL, *new_fro = NULL, *fro_next = NULL;

	/*Starting at next since a list must have atleast 2 items for sorting*/
	if (list && *list && (*list)->next)
		to = (*list)->next;

	while (to)
	{
		fro = to->prev;
		to = to->next;
		while (fro && fro->n > fro->next->n)
		{
			new_fro = fro->prev;
			fro_next = fro->next;
			if (!swap_list(&fro, &fro_next))
				return;

			fro = new_fro;
			if ((*list)->prev)
				*list = fro_next;

			print_list(*list);
		}
	}
}

/**
 * swap_list -
 * @n_a:
 * @n_b:
 *
 * Return: 1 on success, 0 on failure
 */
int swap_list(listint_t **n_a, listint_t **n_b)
{
	listint_t temp = {0, NULL, NULL}, *copy = NULL;

	if (!n_a || !(*n_a) || !n_b || !(*n_b))
		return (0);

	/*Separating n_a and n_b with a tmporary node*/
	if ((*n_a)->next == *n_b)
	{
		/* Insert "temp" in between them (after n_a) */
		(*n_a)->next = &temp;
		(*n_b)->prev = &temp;
		temp.next = *n_b;
		temp.prev = *n_a;
	}
	else if ((*n_a)->prev == *n_b)
	{
		/* Insert "temp" in between them (before n_a) */
		(*n_a)->prev = &temp;
		(*n_b)->next = &temp;
		temp.next = *n_a;
		temp.prev = *n_b;
	}

	/*Handle n_a's neighbours*/
	if ((*n_a)->prev)
		(*n_a)->prev->next = *n_b;

	if ((*n_a)->next)
		(*n_a)->next->prev = *n_b;

	/*Handle n_b's neighbours*/
	if ((*n_b)->prev)
		(*n_b)->prev->next = *n_a;

	if ((*n_b)->next)
		(*n_b)->next->prev = *n_a;

	/*Swapping next pointers*/
	copy = (*n_a)->next;
	(*n_a)->next = (*n_b)->next;
	(*n_b)->next = copy;

	/*Swapping prev pointers*/
	copy = (*n_a)->prev;
	(*n_a)->prev = (*n_b)->prev;
	(*n_b)->prev = copy;
	/*Remove temp from list*/
	if (temp.next)
	{
		temp.next->prev = temp.prev;
		temp.prev->next = temp.next;
	}

	return (1);
}
