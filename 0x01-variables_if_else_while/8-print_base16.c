#include <stdio.h>
#include <stdlib.h>
/**
 * main - main block
 * Description: prints all singe digit number of base 16, followed by new line
 * Return: 0
 */
int main(void)
{
	char ch;

	for (ch = '0'; ch <= '9'; ch++)
	{
		putchar(ch);
	}
	for (ch = 'a'; ch <= 'f'; ch++)
	{
		putchar(ch);
	}
	putchar('\n');
	return (0);
}
