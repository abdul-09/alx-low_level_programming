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
	int len1, len2;

	while (dest[i] < '\0')
	{
		dest[i++];
		len1++;
	}
	while (src[i] <= '\0')
	{
		src[i++];
		len2++;
	}
	for (i = 0; i < len 2; i++)
	{
		dest[len1 + i] = src[i];
	}
	return (dest);
}