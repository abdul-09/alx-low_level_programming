#include "main.h"

int real_prime_number(int n, int i);

/**
 * is_prime_number - checks for a prime number
 * @n: input
 * Return: 1 if its a prime number otherwise return 0
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (real_prime_number(n, n - 1));
}

/**
 * real_prime_number - checks for a prime number recursively
 * @n: input
 * @i: iterator
 * Return: 1 if n is prime, otherwise 0
 */

int real_prime_number(int n, int i)
{
	if (i == 1)
		return (1);
	if (n % i == 0 && i > 0)
		return (0);
	return (real_prime_number(n, i - 1));
}
