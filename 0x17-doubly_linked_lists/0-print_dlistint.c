#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to head of list
 * Return: number of nodes in the list
*/
size_t print_dlistint(const dlistint_t *h)
{
	size_t total_nodes = 0;
	const dlistint_t *temp;

	if (!h)
		return (total_nodes);
	temp = h;
	while (temp)
	{
		printf("%d\n", temp->n);
		total_nodes++;
		temp = temp->next;
	}
	return (total_nodes);
}
