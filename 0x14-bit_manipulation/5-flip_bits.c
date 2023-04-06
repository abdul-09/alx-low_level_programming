#include "main.h"

/**
 * flip_bits - counts the number of bits to flip to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, num = 0;
	unsigned long int present;
	unsigned long int special = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		present = special >> i;
		if (present & 1)
			num++;
	}

	return (num);
}
