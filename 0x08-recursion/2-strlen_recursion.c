#include "main.h"

/**
 * _strlen_recursion - prints length of a string
 * @s: string to be counted
 * Return: always 0 (success)
 */

int _strlen_recursion(char *s)
{
	unsigned int len = 0;

	if (*s)
	{
		len++;
		len += _strlen_recursion(s + 1);
	}
	return (len);
}
