#include "main.h"

/**
 * binary_to_uint - converts binary number to unsigned int
 * @b: string of binary numbers to be converted
 *
 * Return: the converted number
 */

unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	unsigned int value = 0;

	if (!b)
		return (0);

	while (b[i])
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		value = 2 * value + (b[i] - '0');
		i++;
	}

	return (value);
}
