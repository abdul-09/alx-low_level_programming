#include "main.h"

/**
 * _puts_recursion - prints a string, followed by a new line
 * @s: string to be printed
 * Return: always 0 (success)
 */

void _puts_recursion(char *s)
{
	if (*s)
	{
		_putchar(*S);
		_puts_recursion(s + 1);
	}
	else
		_putchar('\n');
}
