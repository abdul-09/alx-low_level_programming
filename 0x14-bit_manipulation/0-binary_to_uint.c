#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string that has the binary number
 * Return: the converted number
 */

unsigned int binary_to_uint(const char *b)
{
	int j;
	unsigned int decimal_val = 0;

	if (!b)
		return (0);
	j = 0;
	while (b[j])
	{
		if (b[j] < '0' || b[j] > '1')
			return (0);
		decimal_val = 2 * decimal_val + (b[j] - '0');

		j++;
	}

	return (decimal_val);
}
