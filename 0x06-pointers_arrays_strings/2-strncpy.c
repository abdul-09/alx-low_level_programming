#include "main.h"

/**
 * _strncpy - copy a string where most n bytes of src are copied
 * @dest: destination of string
 * @src: string to be copied
 * @n: input value
 *
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int k;

	k = 0;
	while (k < n && src[k] != '\0')
	{
		dest[k] = scr[k];
		k++;
	}
	while (k < n)
	{
		dest[k] = '\0';
		k++;
	}
	return (dest);
}
