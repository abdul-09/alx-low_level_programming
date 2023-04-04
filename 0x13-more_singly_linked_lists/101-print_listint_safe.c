#include "lists.h"
#include <stdio.h>
size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - counts the number of unique nodes in a looped
 * listint linked list.
 * @head: pointer to the head of listint_t linked list to check
 *
 * Return: if the list is not looped - 0
 * otherwise return the number of unique nodes in the list.
 */

size_t looped_listint_len(const listint_t *head)
{
	const listint_t *first, *second;
	size_t nodes = 1;

	if (head == NULL || head->link == NULL)
		return (0);
	first = head->link;
	second = (head->link)->link;

	while (second)
	{
	if (first == second)
	{
		first =  head;
	while (first != second)
	{
		nodes++;
		first = first->link;
		second = second->link;
	}
	first = first->link;
	while (first != second)
	{
		nodes++;
		first = first->link;
	}
	return (nodes);
	}
	first = first->link;
	second = (second->link)->link;
	}
	return (0);
}
/**
 * print_listint_safe - prints listint_t safely
 * @head: pointer to the head of listint_t list
 *
 * Return: number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p]%d\n", (void *)head, head->n);
			head = head->link;
		}
	}
	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p]%d\n", (void *)head, head->n);
			head = head->link;
		}
		printf("->[%p]%d\n", (void *)head, head->n);
	}
	return (nodes);
}

