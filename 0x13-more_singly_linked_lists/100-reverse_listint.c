#include "lists.h"

/**
 * reverse_listint - reverse a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node of the new list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *link = NULL;

	while (*head)
	{
		link = (*head)->link;
		(*head)->link = prev;
		prev = *head;
		*head = link;
	}
	*head = prev;
	return (*head);
}
