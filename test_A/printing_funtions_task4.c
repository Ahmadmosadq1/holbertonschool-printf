#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_unsigned - Prints an unsigned number.
 * @n: The unsigned number to print.
 * @i: Pointer to index in format string.
 * Return: Number of characters printed.
 */

void print_unsigned(unsigned int n, int *i, char *buffer, int buff_count)
{
	int z = 0;
	char *numStr;
	do {
		numStr[z++] = (n % 10) + '0';
		n /= 10;
	} while (n > 0);

	while (z--)
	{
		buffer[buff_count++] = numStr[z];
	}
	*i += 2;
}

/**
 * print_octal - Prints a number in octal format.
 * @n: The unsigned number to print.
 * @i: Pointer to index in format string.
 * Return: Number of characters printed.
 */

void print_octal(unsigned int n, int *i, char *buffer, int buff_count)
{
	int z = 0;
	char *numStr;

	do {
		numStr[z++] = (n % 8) + '0';
		n /= 8;
	} while (n > 0);

	while (z--)
	{
		buffer[buff_count] = numStr[z];
	}
	*i += 2;
}


/**
 * print_hex - Prints a number in hexadecimal format.
 * @n: The unsigned number to print.
 * @format: 'x' for lowercase, 'X' for uppercase.
 * @i: Pointer to index in format string.
 * Return: Number of characters printed.
 */

void print_hexa(unsigned int n, char format, int *i, char *buffer, int buff_count)
{
	int z = 0;
	int digit = 0;
	char base_char;

	if (format == 'X')
		base_char = 'A';
	else
		base_char = 'a';

	do {
		digit = n % 16;
		if (digit < 10)
			numStr[z++] = digit + '0';
		else
			numStr[z++] = digit - 10 + base_char;
		n /= 16;
	} while (n > 0);

	while (z--)
	{
		
	}
	*i += 2;
}
