#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_unsigned - Prints an unsigned number.
 * @n: The unsigned number to print.
 * @i: Pointer to index in format string.
 * Return: Number of characters printed.
 */

int print_unsigned(unsigned int n, int *i)
{
	int count = 0;
	char buffer[];
	int index = 0;

	do {
		buffer[index++] = (n % 10) + '0';
		n /= 10;
	} while (n > 0);

	while (index--)
	{
		write(1, &buffer[index], 1);
		count++;
	}
	*i += 2;
	return (count);
}

/**
 * print_octal - Prints a number in octal format.
 * @n: The unsigned number to print.
 * @i: Pointer to index in format string.
 * Return: Number of characters printed.
 */

int print_octal(unsigned int n, int *i)
{
	int count = 0;
	char buffer[];
	int index = 0;

	do {
		buffer[index++] = (n % 8) + '0';
		n /= 8;
	} while (n > 0);

	while (index--)
	{
		write(1, &buffer[index], 1);
		count++;
	}
	*i += 2;
	return (count);
}


/**
 * print_hex - Prints a number in hexadecimal format.
 * @n: The unsigned number to print.
 * @format: 'x' for lowercase, 'X' for uppercase.
 * @i: Pointer to index in format string.
 * Return: Number of characters printed.
 */

int print_hexa(unsigned int n, char format, int *i)
{
	int count = 0;
	char buffer[];
	int index = 0;
	int digit = 0;
	char base_char;

	if (format == 'X')
		base_char = 'A';
	else
		base_char = 'a';

	do {
		digit = n % 16;
		if (digit < 10)
			buffer[index++] = digit + '0';
		else
			buffer[index++] = digit - 10 + base_char;
		n /= 16;
	} while (n > 0);

	while (index--)
	{
		write(1, &buffer[index], 1);
		count++;
	}
	*i += 2;
	return (count);
}
