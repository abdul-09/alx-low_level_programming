#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - prints name of a function
 * @name: name to be printed
 * @f: pointer to function
 * Return: void
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
