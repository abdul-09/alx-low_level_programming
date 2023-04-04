#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index to add the new node
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new;

	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);
	new->n = n;
	new->link = NULL;
	if (idx == 0)
	{
		new->next = *head;
		return (new);
	}
	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			new->link = temp->link;
			temp->link = new;
			return (new);
		}
		else
			temp = temp->link;
	}
	return (NULL);
}
