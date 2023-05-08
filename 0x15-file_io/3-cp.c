#include "main.h"
#include <stdio.h>

/**
 * error_checker - checks if files can be opened
 * @file_from: source of the file
 * @file_to: destination of the file
 * @argv: argument vector
 * Return: void
 */
void error_checker(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - copies contents of a file to another file
 * @argc: the number of args given to the program
 * @argv: array of pointers to the args
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int from, err, to;
	ssize_t nchars, wr_val;
	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	from = open(argv[1], O_RDONLY);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	error_checker(from, to, argv);

	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(from, buff, 1024);
		if (nchars == -1)
			error_checker(-1, 0, argv);
		wr_val = write(to, buff, nchars);
		if (wr_val == -1)
			error_checker(0, -1, argv);
	}
	err = close(from);
	if (err == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
		exit(100);
	}
	err = close(to);
	if (err == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
		exit(100);
	}
	return (0);
}
