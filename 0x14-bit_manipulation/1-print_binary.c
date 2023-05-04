#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to be printed in binary
 */

void print_binary(unsigned long int n)
{
	int j, count = 0;
	unsigned long int present;

	j = 63;
	while (j >= 0)
	{
		present = n >> j;

		if (present & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');

		j--;
	}
	if (!count)
		_putchar('0');
}
