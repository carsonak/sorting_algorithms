#include "sort.h"

/**
 * insertion_sort_list - insertion sort
 * @list: head linked list
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

			if ((*list)->prev)
				*list = fro_next;

			print_list(*list);
			fro = new_fro;
		}
	}
}

/**
 * swap_list - swaps nodes of a linked list
 * @n_a: address of the pointer to node a
 * @n_b: address of the pointer to node b
 *
 * Description: this function will swap nodes in a list. If the nodes
 * neighbour each other it will separate them with a temporary node
 * so that pointer references are not accidentally lost
 *
 * Return: 1 on success, 0 on failure
 */
int swap_list(listint_t **n_a, listint_t **n_b)
{
	listint_t temp = {0, NULL, NULL}, *copy = NULL;

	if (!n_a || !(*n_a) || !n_b || !(*n_b))
		return (0);

	/*Separating n_a and n_b with a tmporary node*/
	sep_nodes(n_a, n_b, &temp);

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

/**
 * sep_nodes - if node a and node b are neighbours, place a temporary node
 * in between them
 * @n_a: address of the pointer to node a
 * @n_b: address of the pointer to node b
 * @separator: pointer to node to use as a separator
 */
void sep_nodes(listint_t **n_a, listint_t **n_b, listint_t *separator)
{
	if (!n_a || !(*n_a) || !n_b || !(*n_b) || !separator)
		return;

	if ((*n_a)->next == *n_b)
	{
		/*place separator after n_a*/
		(*n_a)->next = separator;
		(*n_b)->prev = separator;
		separator->next = *n_b;
		separator->prev = *n_a;
	}
	else if ((*n_a)->prev == *n_b)
	{
		/*place separator before n_a*/
		(*n_a)->prev = separator;
		(*n_b)->next = separator;
		separator->next = *n_a;
		separator->prev = *n_b;
	}
}
