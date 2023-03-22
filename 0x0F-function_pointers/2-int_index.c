#include "function_pointers.h"

/**
 * int_index - searches for index
 * @array: array to search index from
 * @size: size of array elements
 * @cmp: a pointer to the function to be used to compare values
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
