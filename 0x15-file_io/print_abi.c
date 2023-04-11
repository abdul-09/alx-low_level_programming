#include "main.h"

/**
 * print_abi - prints the ABI version of an ELF header
 * @e_ident: a pointer to an array containing the ELF ABI version
 */

void print_abi(unsigned char *e_ident)
{
	printf(" ABI version:		%d\n",
		e_ident[EI_ABIVERSION]);
}
