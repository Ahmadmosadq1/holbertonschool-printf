#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * print_nonPprintable - Prints a string with non-printable characters.Non-printable characters (0 < ASCII value < 32 or >= 127)
 * @str: The string to print.
 * @i: Pointer to index in format string.
 * Return: Number of characters printed.
 */

int print_nonPrintable(char *str, int *i)
{
	int count = 0;
	char hexa[5]; /* to store \x + tow hexa + \0*/

	if (!str)
		str = "(null)";
	while (*str)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sprintf(hexa, "\\X%02X", (unsigned char)*str);
			write(1, hexa, 4);
			count++;
		}
		else
		{
			write(1, str, 1);
			count++;
		}
		str++;
	}
	*i += 2;
	return (count);
}
