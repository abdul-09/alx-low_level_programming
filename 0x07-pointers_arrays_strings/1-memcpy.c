#include "main.h"

/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 * @src: where to copy memory from
 * @dest: where to copy memory to
 * @n: value of bytes
 * Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int j = 0;

	while (j < n; j++)
	{
		dest[j] = src[j];
		n--;
	}
	return (dest);
}
