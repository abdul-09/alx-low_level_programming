#include "main.h"

/**
 * _strcat - a function that concatenates two strings
 * @dest: string to be concatenated to
 * @src: string to be concatenated from
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int k = 0;

	while (dest[i] !=  '\0')
	{
		i++;
	}
	while (src[k] != '\0')
	{
		dest[i] = src[k];
		i++;
		k++;
	}

	dest[i] = '\0';
	return (dest);
}
