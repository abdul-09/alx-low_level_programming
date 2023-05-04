#include "main.h"

/**
 * get_bit - returns value of a bit at given index
 * @n: number to look for
 * @index: position of the bit
 * Return: value of the bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int val_of_bit;

	if (index > 63)
		return (-1);
	val_of_bit = (n >> index) & 1;

	return (val_of_bit);
}
