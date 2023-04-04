#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: pointer to the first node in the list
 * @index: position of the node to delete
 *
 * Return: 1 (success) or -1 (Fail)
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current = NULL;
	listint_t *temp = *head;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->link;
		free(temp);
		return (1);
	}
	while (i < index - 1)
	{
		if (!temp || !(temp->link))
			return (-1);
		temp = temp->link;
		i++;
	}
	current = temp->link;
	temp->link = current->link;
	free(current);
	return (1);
}
