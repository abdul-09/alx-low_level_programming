#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void display_magic(unsigned char *e_ident);
void display_class(unsigned char *e_ident);
void display_data(unsigned char *e_ident);
void display_version(unsigned char *e_ident);
void display_abi(unsigned char *e_ident);
void display_osabi(unsigned char *e_ident);
void display_type(unsigned int e_type, unsigned char *e_ident);
void display_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);


/**
 * check_elf - checks if a file is an ELF file
 * @e_ident: pointer to an array containing elf magic numbers
 */

void check_elf(unsigned char *e_ident)
{
	int idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (e_ident[idx] != 127 && e_ident[idx] != 'E' &&
				e_ident[idx] != 'L' && e_ident[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * display_magic - prints the magic number of an elf header
 * @e_ident: pointer to an array containing the elf magic numbers
 *
 */
void display_magic(unsigned char *e_ident)
{
	int idx;

	printf(" Magic:		");

	for (idx = 0; idx < EI_NIDENT; idx++)
	{
		printf("%02x", e_ident[idx]);
		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * display_class - prints the class of an elf header
 * @e_ident: a pointer to an array containing the elf class
 *
 */
void display_class(unsigned char *e_ident)
{
	printf(" Class:		");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("None\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * display_data - prints the data of an Elf header
 * @e_ident: pointer to an array containing the elf class
 */
void display_data(unsigned char *e_ident)
{
	printf(" Data:		");
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("None\n");
		break;
	case ELFDATA2LSB:
		printf("Two's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("Two's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * display_version - prints the version of an elf header
 * @e_ident: pointer to an array containing the elf version
 */
void display_version(unsigned char *e_ident)
{
	printf(" Version:		%d", e_ident[EI_VERSION]);

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
 * display_abi - prints the ABI version of an elf header
 * @e_ident: pointer to an array containing the elf ABI version
 *
 */
void display_abi(unsigned char *e_ident)
{
	printf(" ABI Version:		%d\n", e_ident[EI_ABIVERSION]);
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
void display_entry(unsigned long int e_entry, unsigned char *e_ident)
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
		printf("%#lx\n", e_entry);
}
/**
 * close_elf - closes an elf file
 * @elf: file descriptor of the elf file
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}
/**
 * main - displays the info contained in the elf header
 * at the start of elf file
 * @argc: the number of arguments given to the program
 * @argv: array of pointers to the args
 *
 * Return: 0 on success
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int p, rd;

	p = open(argv[1], O_RDONLY);
	if (p == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(p);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	rd = read(p, header, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(header);
		close_elf(p);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	display_magic(header->e_ident);
	display_class(header->e_ident);
	display_data(header->e_ident);
	display_version(header->e_ident);
	display_osabi(header->e_ident);
	display_abi(header->e_ident);
	display_type(header->e_type, header->e_ident);
	display_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(p);
	return (0);
}
