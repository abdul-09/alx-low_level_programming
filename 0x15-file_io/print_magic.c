#include "main.h"

/**
 * print_magic - prints magic number of an ELF header file
 * @e_ident: a pointer to an array containing the ELF magic numbers
 *
 * Description: Magic numbers are seperated by spaces
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf(" Magic:	");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
