#include "main.h"

/**
 * append_text_to_file - appends text at the end of file
 * @filename: a pointer to the name of the file
 * @text_content: the string to add to the end of file
 * Return: -1 if the function fails or filename is NULL
 * -1 if the file does not exists ot the user lacks write permission
 *  otherwise 1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int p, wr, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}
	p = open(filename, O_WRONLY | O_APPEND);
	wr = write(p, text_content, len);

	if (p == -1 || wr == -1)
		return (-1);
	close(p);
	return (1);
}
