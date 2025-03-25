#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"


int _printf(const char *format, ...)
{
	int i = 0;
	char *str;
	va_list arg;
	int printed = 0;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(arg, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			char c;

			c = va_arg(arg, int);
			write(1, &c, 1);
			printed++;
			i += 2;
			continue;
		}

		if (format[i] == '%' && format[i + 1] == 's')
		{
			str = va_arg(arg, char *);

			if (str == NULL)
				str = "(null)";
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
	
		write(1, &format[i], 1);
        	printed++;
        	i++;
    }
	write(1, "\n", 1);
	va_end(arg);
   	return(printed);
}
