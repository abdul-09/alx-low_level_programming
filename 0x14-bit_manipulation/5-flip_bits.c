#include "main.h"

/**
 * flip_bits - counts the number of bits to change to get
 * from one number to another
 * @n: first number
 * @m: second number
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int j, count = 0;
	unsigned long int curr;
	unsigned long int special = n ^ m;

	j = 63;
	while (j >= 0)
	{
		curr = special >> j;
		if (curr & 1)
			count++;
		j--;
	}
	return (count);
}
