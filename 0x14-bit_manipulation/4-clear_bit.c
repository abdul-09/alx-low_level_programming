#include "main.h"

/**
 * clear_bit - sets the value of given bit to 0
 * @n: pointer to the nember to change
 * @index: position of bit to clear
 *
 * Return: 1 (success) or -1 (fail)
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
