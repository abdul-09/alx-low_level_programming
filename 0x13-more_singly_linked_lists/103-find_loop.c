#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer linked list to seach for
 *
 * Return: address of the node where the loop starts 0r NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first = head;
	listint_t *last = head;

	if (!head)
		return (NULL);
	while (first && last && last->link)
	{
		last = last->link->link;
		first = first->link;

		if (last == first)
		{
			first = head;
		while (first != last)
		{
			first = first->next;
			last = last->next;
		}
		return (last);
		}
	}
	return (NULL);
}
