#include "main.h"
#include <stdio.h>

char *create_buf(char *file);
void close_file(int file_d);

/**
 * create_buf - allocates 1024bytes for a buffer
 * @file: name of the file and why the buffer is created for
 * Return: a pointer to newly allocated buffer
 */
char *create_buf(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);
	if (buff == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buff);
}
/**
 * close_file - closes file descriptors
 * @file_d: the file descriptor to be closed
 */
void close_file(int file_d)
{
	int b;

	b = close(file_d);

	if (b == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", file_d);
		exit(100);
	}
}

/**
 * main - copies contents of a file to another file
 * @argc: the number of args given to the program
 * @argv: array of pointers to the args
 * Exit description: if the argument is incorrect - exit code 97
 * if file_from does not exist or can't be read - exit code 98
 * if file_to can't be created or written to - exit code 99
 * if file_to or file_from can't be closed - exit code 100
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int from, wr, to, rd;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buff = create_buf(argv[2]);
	from = open(argv[1], O_RDONLY);
	rd = read(from, buff, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		wr = write(to, buff, rd);
		if (to == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		rd = read(from, buff, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (rd > 0);

	free(buff);
	close_file(from);
	close_file(to);

	return (0);
}
