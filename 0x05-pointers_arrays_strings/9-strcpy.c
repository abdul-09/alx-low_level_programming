
#include "main.h"

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int b = 0;

	for (i = 0; i < b; &&src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < b; i++)
		dest[i] = '\0';

	return (dest);
}
