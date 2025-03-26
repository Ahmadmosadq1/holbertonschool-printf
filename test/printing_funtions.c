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
void print_char(char c, int *i)
{
	write(1, &c, 1);
	*i += 2;
}

/**
 * print_number - Prints an integer as a string.
 * @n: integer to be printed.
 * Return: number of characters printed.
 */
int print_number(int n)
{
    char num_str[12];  // Max length for an int is 11 characters + 1 for null terminator
    int len = 0;
    int i = 0;

    // Handle negative numbers
    if (n < 0)
    {
        num_str[len++] = '-';
        n = -n;
    }

    // Convert integer to string
    int temp = n;
    while (temp > 0)
    {
        temp /= 10;
        len++;
    }

    num_str[len] = '\0';

    // Add digits to the string in reverse order
    for (i = len - 1; n > 0; i--)
    {
        num_str[i] = (n % 10) + '0';  // Convert digit to character
        n /= 10;
    }

    // Write the number to stdout
    write(1, num_str, len);
    return (len);
}

