#include "main.h"

/**
 * print_abi - prints the ABI VERSION of an elf header
 * @elf_i: pointer to an array containing elf abi version
 */
void print_abi(unsigned char *elf_i)
{
	printf(" ABI VERSION:	%d\n", elf_i[EI_ABIVERSION]);
}
