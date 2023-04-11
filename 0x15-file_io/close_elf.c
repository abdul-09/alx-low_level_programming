#include "main.h"

/**
 * close_elf - closes an ELF file
 * @elf: file descriptor of the ELF file
 *
 * Description: if the file can't be closed exit with code 98
 */

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}
