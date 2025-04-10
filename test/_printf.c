#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
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
	char *str;
	char c;
	va_list arg;
	int printed = 0;

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = va_arg(arg, int);
			print_char(c, &i);
			continue;
		}
		if (format[i] == '%' && format[i + 1] == 's')
		{
			str = va_arg(arg, char *);
			printed = printed + print_string(str);
			i += 2;
			continue;
		}
		if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, &format[i], 1);
			printed++;
			i += 2;
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
