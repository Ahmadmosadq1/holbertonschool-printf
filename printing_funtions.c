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
	int printed = 0;
	int i = 0;
	char numStr[12];
	unsigned int number;
	int temp;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		printed++;
		number = (unsigned int)(-n);
	}
	else
	{
		number = n;
	}

	temp = number;
	while (temp > 0)
	{
		temp /= 10;
		printed++;
	}
	numStr[printed] = '\0';

	for (i = printed - 1; number > 0; i--)
	{
		numStr[i] = (number % 10) + '0';
		number /= 10;
	}
	write(1, numStr, printed);
	return (printed);
}
