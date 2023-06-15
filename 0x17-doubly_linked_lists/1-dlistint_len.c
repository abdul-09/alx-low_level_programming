
#include "lists.h"

/**
 * dlistint_len - calculates the number of nodes in a list
 * @h: pointer to head node of the list
 * Return: number of nodes
*/
size_t dlistint_len(const dlistint_t *h)
{
	size_t total_nodes = 0;
	const dlistint_t *temp;

	if (!h)
		return (total_nodes);

	temp = h;
	while (temp)
	{
		total_nodes++;
		temp = temp->next;
	}
	return (total_nodes);
}
