#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
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

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			printed += print_char(va_arg(arg, int), &i);
			continue;
		}
		if (format[i] == '%' && format[i + 1] == 's')
		{
			printed = printed + print_string(va_arg(arg, char *), &i);
			continue;
		}
		if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, &format[i], 1);
			printed++;
			i += 2;
			continue;
		}
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			printed += print_number(va_arg(arg, int), &i);
			continue;
		}
		if (format[i] == '%' && format[i + 1] == 'b')
		{
			printed += print_binary(va_arg(arg, int), &i);
			continue;
		}
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		write(1, &format[i], 1);
		printed++;
		i++;
	}
	va_end(arg);
	return (printed);
}
