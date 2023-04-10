#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - allocates 1024 bytes to a buffer
 * @file: the name of the file that buffer is storing chars for
 *
 * Return: a pointer to the new allocated buffer
 */
char *create_buffer(char *file)
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
 * @fd: the file descriptor to be closed
 */

void close_file(int fd)
{
	int cl;

	cl = close(fd);

	if (cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - copies the contents of one file descriptor to another
 * @argc: number of arguments supplied to the program
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on Success
 *
 * Description: if the argument count is incorrect exit with code 97
 * if the file_from doesn't exist or cannot be read exit with code 98
 * if the file_to cannot be created or written to exit with code 99
 * if the file_to or file_from cannot be closed exit with code 100
 */
int main(int argc, char *argv[])
{
	int from, dest, rd, wr;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	rd = read(from, buff, 1024);
	dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		wr = write(dest, buff, rd);
		if (dest == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		rd = read(from, buff, 1024);
		dest = open(argv[2], O_WRONLY | O_APPEND);
	} while (rd > 0);

	free(buff);
	close_file(from);
	close_file(dest);

	return (0);
}
