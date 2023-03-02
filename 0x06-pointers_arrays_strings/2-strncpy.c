#include "main.h"

/**
 * _strncpy - copy a string
 * @dest: destination of string
 * @src: input value
 * @n: input value
 * Return: dest
 */

char* _strncpy(char* dest, char* src, int n)
{
	int k = 0;

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
