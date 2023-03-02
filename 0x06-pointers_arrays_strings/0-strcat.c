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
	int len1 = 0;
	int len2 = 0;

	while (dest[i] !=  '\0')
	{
		i++;
		len1++;
	}
	while (src[i] <= '\0')
	{
		i++;
		len2++;
	}
	for (i = 0; i <= len2; i++)
	{
		dest[len1 + i] = src[i];
	}
	return (dest);
}
