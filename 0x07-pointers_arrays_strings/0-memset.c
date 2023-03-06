#include "main.h"

/**
 * _memset -  fills memory with a constant byte.
 * @s: starting address
 * @b: the value to be filled in
 * @n: number of bytes
 * Return: changed array with new values for n bytes
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return(s);
}
