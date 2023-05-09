#include "main.h"

/**
 * display_osabi - prints the OS/ABI of an ELF header
 * @e_ident: a pointer to an array containing the elf version
 */
void display_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI:	");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
 * display_type - prints the type of an elf header
 * @e_ident: a pointer to an array containing elf class
 * @e_type: elf type
 */
void display_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf(" Type:		");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}
/**
 * display_entry - prints an entry point of an elf header
 * @e_entry: the address of the elf entry point
 * @e_ident: a pointer to an array containing the elf class
 */
void display_entry(unsigned long int e_entry, unsigned char *elf_i)
{
	printf(" Entry point address:	");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#x\n", e_entry);
}
/**
 * display_version - prints the version of an elf header
 * @e_ident: pointer to an array containing elf version
 */
void display_version(unsigned char *e_ident)
{
	printf(" Version:	%d", e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}
/**
 * close_elf - closes an elf file
 * @elf: file descriptor of the elf file
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf("STDERR_FILENO, Error: Can't close fd %d\n", elf);
		exit(98);
	}
}
