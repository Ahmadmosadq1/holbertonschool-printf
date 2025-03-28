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
void print_string(char *format, int *i, char *buffer, int buff_count)
{
	int j = 0;
	char *null_output;
	int e = 0;

	if (format == NULL)
	{
		while (null_output)
			buffer[buff_count] = null_output[e];
	}
	while (format[j] != '\0')
	{
		buffer[buff_count++] = format[j];
	}
	*i += 2;
}
/**
 * print_char - Entry point
 *
 * Description: This function prints a charachter for %c format.
 * @c: charachter.
 * @i: increment i to skip %c.
 * Return: J
 */
 void print_char(char c, int *i, char *buffer, int buff_count)
{
	buffer[buff_count++] = c;
	*i += 2;
}

/**
 * print_number - Prints an integer as a string.
 * @n: integer to print it.
 * @i: incremant pointer
 * Return: total of number of characters printed.
 */

void print_number(int n, int *i, char *buffer, int buff_count)
{
	int z = 0;
	unsigned int  number;
	char *numStr;

	if (n == 0)
		buffer[buff_count++] = '0';
	if (n < 1)
	{
		buffer[buff_count] = '-';
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
		 buffer[buff_count++] = numStr[z];
	}
	*i += 2;
}
/**
 * print_binary - converts decimal to binary.
 * @n: integer to convert  it to binary.
 * @i: a incremant  pointer
 * Return: total of number of characters printed.
 */

void print_binary(unsigned int n, int *i, char *buffer, int buff_count)
{
	unsigned int temp = n;
	int bits = 0;
	int z = 0;
	char *numStr;
	char null_output[8] = "(null)";
	int e = 0;
	
	while (temp > 0)
	{
		temp /= 2;
		bits++;
	}
	if (n == 0)
	{
		buffer[buff_count] = '0';
		*i += 2;
	}

	
	numStr = (char *) malloc(bits * sizeof(char));/*allocate memory dynamically.*/
	if (numStr == NULL)
	{
		while (null_output[e])
			buffer[buff_count++] = null_output[e];
	}

	do {
		numStr[z++] = (n % 2) + '0';
		n /= 2;
	} while (n > 0);

	while (z--)
	{
		buffer[buff_count++] = numStr[z];
	}
	*i += 2;
	free(numStr);
}


