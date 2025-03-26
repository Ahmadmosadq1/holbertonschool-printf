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
int print_string(char *str)
{
	int j = 0;

	if (str == NULL)
		str = "(null)";
	while (str[j] != '\0')
	{
		j++;
	}
	write(1, str, j);
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
 * print_char - Entry point
 *
 * Description: This function prints a charachter for %c format.
 * @c: charachter.
 * @i: increment i to skip %c.
 * Return: J
 */
int print_int(int int_i, int* i)
{
	int *butffer;
	int j = 0;
	int count = 0;

	while (format[j])
	{
		buffer[i] = (int_i % 10 ) + '0';
		(int_i /= 10) + '0';
		++j;
	}
	
	while (j--)
	{
		write(1, &buffer[j], 1);
		count++;
	}
	return (count);
}
