#include "sort.h"

/**
 * free_dlistint - frees a doubly linked list
 * @head: head of the doubly linked list
 */
void free_dlistint(listint_t *head)
{
	if (head)
	{
		while (head->next)
		{
			head = head->next;
			free(head->prev);
		}

		free(head);
	}
}
