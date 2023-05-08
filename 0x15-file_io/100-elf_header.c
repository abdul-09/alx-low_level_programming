#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void check_elf(unsigned char *elf_i);
void print_magic(unsigned char *elf_i);
void print_class(unsigned char *elf_i);
void print_data(unsigned char *elf_i);
void print_version(unsigned char *elf_i);
void print_abi(unsigned char *elf_i);
void print_osabi(unsigned char *elf_i);
void print_type(unsigned int e_type, unsigned char *elf_i);
void print_entry(unsigned long int e_entry, unsigned char *elf_i);
void close_elf(int elf);

/**
 * check_elf - checks if a file is an ELF file
 * @elf_i: a pointer to an array containing ELF magic numbers
 */
void check_elf(unsigned char *elf_i)
{
	int idx;

	idx = 0;
	while (idx < 4)
	{
		if (elf_i[idx] != 127 &&
			elf_i[idx] != 'E' &&
			elf_i[idx] != 'L' &&
			elf_i[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
		idx++;
	}
}
/**
 * print_magic - prints magic numbers of the elf header
 * @elf_i: a pointer to an array containing the ELF magic numbers
 */
void print_magic(unsigned char *elf_i)
{
	int idx;

	printf(" Magic:	");
	idx = 0;
	while (idx < EI_NIDENT)
	{
		printf("%02x", elf_i[idx]);
		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
		idx++;

	}
}
/**
 * print_class - prints the class of an ELF header
 * @elf_i: poiter to an array containing the ELF class
 */
void print_class(unsigned char *elf_i)
{
	printf(" Class:		");

	switch (elf_i[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_i[EI_CLASS]);
	}
}
/**
 * print_data - prints the data of an ELF header
 * @elf_i: a pointer to an array containing the ELF data
 */
void print_data(unsigned char *elf_i)
{
	printf(" Data:		");

	switch (elf_i[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_i[EI_CLASS]);
	}
}
/**
 * main - displays the info in the ELF header at the start of an elf file
 * @argc: the number of arguments given to the program
 * @argv: array of pointers to the arguments
 * Return: 0 on success
 */
int main(int __attribute__((__unused__))argc, char *argv[])
{
	Elf64_Ehdr *h;
	int p, rd;

	p = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	h = malloc(sizeof(Elf64_Ehdr));
	if (h == NULL)
	{
		close_elf(p);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	rd = read(p, h, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(h);
		close_elf(p);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	check_elf(h->elf_i);
	printf("ELF Header:\n");
	print_magic(h->elf_i);
	print_class(h->elf_i);
	print_data(h->elf_i);
	print_version(h->elf_i);
	print_osabi(h->elf_i);
	print_abi(h->elf_i);
	print_type(h->e_type, h->elf_i);
	print_entry(h->e_type, h->elf_i);

	free(h);
	close_elf(p);
	return (0);
}
