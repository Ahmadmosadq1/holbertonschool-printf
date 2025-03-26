#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_string - Entry point
 * Description: This function prints a string for %s format.
 * @format: data type
 * Return: J
 */
int print_string(char *format)
{
	int j = 0;

	if (format == NULL)
		format = "(null)";
	while (format[j] != '\0')
	{
		j++;
	}
	write(1, format, j);
	return (j);
}
/**
 * print_char - Entry point
 *
 * Description: This function prints a charachter for %c format.
 * @c: charachter.
 * @i: increment i to skip %c.
 * Return: J
 */
int print_char(char c, int *i)
{
	write(1, &c, 1);
	*i += 2;
	return (1);
}

/**
 * print_number - Prints an integer as a string.
 * @n: integer to print it.
 * Return: total of number of characters printed.
 */

int print_number(int n)
{
	char numStr[20];
	int printed = 0;
	int i = 0;
	int conv_str;

	if (n < 0)
	{
		numStr[printed++] = '-';
		n = -n;
	}

	conv_str = n;

	while (conv_str > 0)
	{
		conv_str /= 10;
		printed++;
	}
	numStr[printed] = '\0';

	for (i = printed - 1; n > 0; i--)
	{
		numStr[i] = (n % 10) + '0';
		n /= 10;
	}
	write(1, numStr, printed);
	return (printed);
}

