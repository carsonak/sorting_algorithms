#include "sort.h"

int insert_after(listint_t **dest, listint_t **src);
int insert_top(listint_t **head, listint_t **src);

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
	listint_t *to = NULL, *fro = NULL, *new_to = NULL;
	int swapped = 0;

	/*Starting at next since a list must have atleast 2 items for sorting*/
	if (list && *list && (*list)->next)
		to = (*list)->next;

	while (to)
	{
		swapped = 0;
		fro = to->prev;
		/*Find suitable position of "to" in the sorted side*/
		while (fro && fro->n > to->n)
			fro = fro->prev;

		new_to = to->next;
		if (fro && fro != to->prev)
		{
			/*Insert "to" after "fro"*/
			swapped = insert_after(&fro, &to);
			if (!swapped)
				return;
		}
		else if (!fro)
		{
			/*Insert at the beginning of the list*/
			swapped = insert_top(list, &to);
			if (!swapped)
				return;
		}

		/*Update head pointer if necessary*/
		if ((*list)->prev)
			*list = to;

		if (swapped)
			print_list(*list);

		to = new_to;
	}
}

/**
 * insert_after - insert src node after dest node
 * @dest: address of the node to insert after
 * @src: address of the node to insert
 *
 * Return: 1 on success, 0 on failure
 */
int insert_after(listint_t **dest, listint_t **src)
{
	if (!src || !dest || !(*dest))
		return (0);

	if ((*dest)->next == *src)
		return (1);

	if (*src)
	{
		/*Updating neighbours of src*/
		if ((*src)->next)
			(*src)->next->prev = (*src)->prev;

		(*src)->prev->next = (*src)->next;

		/*Updating src pointers*/
		(*src)->next = (*dest)->next;
		(*src)->prev = *dest;
	}

	/*Updating dest next pointer and forward neighbour*/
	(*dest)->next->prev = (*src);
	(*dest)->next = (*src);
	return (1);
}

/**
 * insert_top - makes src the new head of the list
 * @head: address of the head of the list
 * @src: address of the node to insert
 *
 * Return: 1 on success, 0 on failure
 */
int insert_top(listint_t **head, listint_t **src)
{
	if (!src || !(*src) || !head || !(*head))
		return (0);

	/*Updating neighbours of src*/
	if ((*src)->next)
		(*src)->next->prev = (*src)->prev;

	(*src)->prev->next = (*src)->next;

	/*Updating src pointers*/
	(*src)->next = *head;
	(*src)->prev = NULL;

	/*Updating head neighbours and head*/
	(*head)->prev = *src;
	*head = *src;
	return (1);
}
