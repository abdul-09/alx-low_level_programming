#include "main.h"

/**
 * print_rev -  prints a string, in reverse, followed by a new line
 * @s: string to print
 */

void print_rev(char *s)
{
	int i;
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	s--;
	for (i = len; i > 0; i--)
	{
		_putchar(*s);
		s--;
	}
	_putchar('\n');
}
