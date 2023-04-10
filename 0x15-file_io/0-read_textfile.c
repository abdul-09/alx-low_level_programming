#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints to STDOUT
 * @filename: textfile to read
 * @letters: number of letters to read and print
 *
 * Return: actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t fd;
	ssize_t wr;
	ssize_t r;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buff = malloc(sizeof(char) * letters);
	r = read(fd, buff, letters);
	wr = write(STDOUT_FILENO, buff, r);

	free(buff);
	close(fd);

	return (wr);
}
