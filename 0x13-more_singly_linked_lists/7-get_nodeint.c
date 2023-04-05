#include "lists.h"

/**
 * get_nodeint_at_index - returns of node of linked list at a certain index
 * @head: first node of linked list
 * @index: index of node to return
 *
 * Return: pointer to the node we're searching for, or NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	return (temp ? temp : NULL);
}
