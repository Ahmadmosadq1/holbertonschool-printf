#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>
/**
 * _printf - Entry point
 * Description: This function mimics the standard printf.
 * @format: the data type.
 * Return:printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	va_list arg;
	int printed = 0;
	char buffer[1024];
	int buff_count = 0;

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			 print_char(va_arg(arg, int), &i, buffer, buff_count);
			continue;
		}
		if (format[i] == '%' && format[i + 1] == 's')
		{
			print_string(va_arg(arg, char *), &i, buffer, buff_count);
			continue;
		}
		if (format[i] == '%' && format[i + 1] == '%')
		{
			buffer[buff_count] = format[i];
			i += 2;
			continue;
		}
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			print_number(va_arg(arg, int), &i, buffer, buff_count);
			continue;
		}
		if (format[i] == '%' && format[i + 1] == 'b')
		{
			print_binary(va_arg(arg, int), &i, buffer, buff_count);
			continue;
		}
		if (format[i] == '%' && format[i + 1] == 'u')
		{
			print_unsigned(va_arg(arg, unsigned int), &i, buffer, buff_count);
			continue;
		}
		if (format[i] == '%' && format[i + 1] == 'o')
		{
			print_octal(va_arg(arg, unsigned int), &i, buffer, buff_count);
			continue;
		}
		if (format[i] == '%' && (format[i + 1] == 'x' || format[i + 1] == 'X'))
		{
			print_hexa(va_arg(arg, unsigned int), format[i + 1], &i, buffer, buff_count);
			continue;
		}
		if (format[i] == '%' && format[i + 1] == '\0')
		{
		buffer[buff_count] = format[i];
		return (-1);
	}
		i++;
	}
	write(1, &buffer, buff_count);
	printed++;
	va_end(arg);
	return (printed);
}
