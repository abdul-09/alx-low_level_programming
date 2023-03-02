#include "main.h"

/**
 * _strncpy - copy a string using at most n bytes from src
 * @dest: input
 * @src: input
 * @n: input
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int k = 0;

	while (k < n && src[k] != '\0')
	{
		dest[k] = scr[k];
		k++;
	}
	while (k < n; k++)
		dest[k] = '\0';
	return (dest);
}
