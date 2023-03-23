#include "function_pointers.h"

/**
 * int_index - return index place if comparison = true, else -1
 * @array: array to search index from
 * @size: size of array elements
 * @cmp: pointer to func of one of the 3 in main
 * Return: 0
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || size <= NULL || cmp == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}

	return (-1);
}
