#include "lists.h"

/**
 * sum_listint - calculates sum of all data in the linked list
 * @head: pointer to first node of linked list
 *
 * Return: sum
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}

	return (sum);
}
