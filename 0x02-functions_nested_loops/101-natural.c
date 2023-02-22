#include <stdio.h>

/**
 * main - prints the sum all the multiples of 3 or 5 until 1024
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i, z = 0;

	while (i < 1024)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			z += i;
		}
		i++;
	}
	printf(" % d\n", z);
	return (0);
}
