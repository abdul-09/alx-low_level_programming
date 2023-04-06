#include "main.h"

/**
 * print_binary - prints binary representation of a number
 * @n: number to print to binary
 */

void print_binary(unsigned long int n)
{
	int i, num = 0;
	unsigned long int present;

	for (i = 63; i >= 0; i--)
	{
		present = n >> i;

		if (present & 1)
		{
			_putchar('1');
			num++;
		}
		else if (num)
			_putchar('0');
	}
	if (!num)
		_putchar('0');
}
