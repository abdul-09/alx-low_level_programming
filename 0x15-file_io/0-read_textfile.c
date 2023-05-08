#include "main.h"

/**
 * read_textfile - reads text file and prints to STDOUT
 * @filename: textfile to read
 * @letters: number of letters to read
 * Return: actual number of bytes read and printed
 * 0 if function fails or filename is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t file_desc;
	ssize_t wr;
	ssize_t rd;

	file_desc = open(filename, O_RDONLY);
	if (file_desc == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	rd = read(file_desc, buffer, letters);
	wr = write(STDOUT_FILENO, buffer, rd);

	free(buffer);
	close(file_desc);
	return (wr);
}
