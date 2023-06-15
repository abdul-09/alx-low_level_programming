#include "lists.h"

/**
 * free_dlistint - frees a list
 * @head: pointer to head node
*/
void free_dlistint(dlistint_t *head)
{
	dlistint_t *old_ptr, *new_ptr;

	/* to keep track of node(s) when traversing */
	old_ptr = head;
	new_ptr = head;

	while (new_ptr)
	{
		new_ptr = new_ptr->next;
		free(old_ptr);
		old_ptr = new_ptr;
	}
}
