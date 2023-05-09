#include "main.h"

/**
 * display_abi - prints the ABI VERSION of an elf header
 * @e_ident: pointer to an array containing elf abi version
 */
void display_abi(unsigned char *e_ident)
{
	printf(" ABI VERSION:	%d\n", e_ident[EI_ABIVERSION]);
}
