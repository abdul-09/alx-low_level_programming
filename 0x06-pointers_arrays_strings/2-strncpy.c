#include "main.h"

/**
 * _strncpy - copy a string where most n bytes of src are copied
 * @dest: destination of string
 * @src: string to be copied
 * @n: input value
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int k;

	for (k = 0; k < n && src[k] != '\0'; k++)
	{
		dest[k] = scr[k];
	}
	for (k < n; k++)
	{
		dest[k] = '\0';
	}

	return (dest);
}
