#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

/**
 * print_string - Entry point
 * Description: This function prints a string for %s format.
 * @format: data type
 * @i: an increment pointer.
 * Return: J
 */
int print_string(char *format, int *i)
{
	int j = 0;

	if (format == NULL)
		format = "(null)";
	while (format[j] != '\0')
	{
		j++;
	}
	write(1, format, j);
	*i += 2;
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
 * @i: incremant pointer
 * Return: total of number of characters printed.
 */

int print_number(int n, int *i)
{
	int printed = 0;
	int z = 0;
	int count = 0;
	char numStr[12]; /*allocating memory by hardcoding*/
	unsigned int  number;

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
		number = (unsigned int)(n);
	}

	do {
		numStr[z++] = (number % 10) + '0';
		number /= 10;
		} while (number > 0);

	while (z--)
	{
		write(1, &numStr[z], 1);
		printed += count;
	}
	*i += 2;
	return (printed);
}
/**
 * print_binary - converts decimal to binary.
 * @n: integer to convert  it to binary.
 * @i: a incremant  pointer
 * Return: total of number of characters printed.
 */

int print_binary(unsigned int  n, int *i)
{
	int temp = n;
	int bits = 0;
	int z = 0;
	int count = 0;
	char *numStr;

	while (temp > 0)
	{
		temp /= 2;
		bits++;
	}
	if (n == 0)
	{
		write( 1, "0", 1);
		return(1);
	}
	numStr = (char *) malloc(bits * sizeof(char));/*allocate memory dynamically.*/
	do {
		numStr[z++] = (n % 2) + '0';
		n /= 2;
	} while (n > 0);

	while (z--)
	{
		write(1, &numStr[z], 1);
		count++;
	}
	*i += 2;
	free(numStr);
	return (count);
}

