#ifndef LISTS_H
#define LISTS_H
#include <stdlib.h>
#include <stdio.h>

size_t print_listint(const listint_t *h);
size_t listint_len(listint_t *h);
listint_t *add_nodeint(listint_t **head, const int n);
listint_t *add_nodeint_end(listint **head, const int n);
void free_listint(listint_t *head);
void free_listint(listint_t **head);
int pop_listint(listint_t **head);
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);
int sum_listint(listint_t *head);
listint_t *insertnodeint_at_index(listint_t **head, unsigned int idx, int n);
int delete_nodeint_at_index(listint_t **head, unsigned int index);
listint_t *reverse_listint(listint_t **head);
size_t print_listint_safe(const listint *head);
size_t free_listint_safe(listint_t **h);
listint *find_listint_loop(listint_t *head);

/**
 * struct listint_t - singly linked list
 * @n: integer
 * @link: points to the next node
 *
 */

struct listint_t
{
	int n;
	struct listint_t *link;
};


#endif
