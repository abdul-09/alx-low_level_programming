#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void check_elf(unsigned char *e_ident);
void display_magic(unsigned char *e_ident);
void display_class(unsigned char *e_ident);
void display_data(unsigned char *e_ident);

/**
 * check_elf - checks if a file is an ELF file
 * @e_ident: a pointer to an array containing ELF magic numbers
 */
void check_elf(unsigned char *e_ident)
{
	int idx;

	idx = 0;
	while (idx < 4)
	{
		if (e_ident[idx] != 127 &&
			e_ident[idx] != 'E' &&
			e_ident[idx] != 'L' &&
			e_ident[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
		idx++;
	}
}
/**
 * display_magic - prints magic numbers of the elf header
 * @e_ident: a pointer to an array containing the ELF magic numbers
 */
void display_magic(unsigned char *e_ident)
{
	int idx;

	printf(" Magic:	");
	idx = 0;
	while (idx < EI_NIDENT)
	{
		printf("%02x", e_ident[idx]);
		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
		idx++;

	}
}
/**
 * display_class - prints the class of an ELF header
 * @e_ident: poiter to an array containing the ELF class
 */
void display_class(unsigned char *e_ident)
{
	printf(" Class:		");

	switch (e_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * display_data - prints the data of an ELF header
 * @e_ident: a pointer to an array containing the ELF data
 */
void display_data(unsigned char *e_ident)
{
	printf(" Data:		");

	switch (e_ident[EI_DATA])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * main - displays the info in the ELF header at the start of an elf file
 * @argc: the number of arguments given to the program
 * @argv: array of pointers to the arguments
 * Return: 0 on success
 */
int main(int __attribute__((unused))argc, char *argv[])
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
	display_entry(header->e_type, header->e_ident);

	free(header);
	close_elf(p);
	return (0);
}
