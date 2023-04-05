#include "lists.h"

/**
 * pop_listint - deletes head node of a linked list
 * @head: pointer to the first element of linked list
 *
 * Return: data inside the elements deleted
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int count;

	if (!head || !*head)
		return (0);
	count = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (count);
}
