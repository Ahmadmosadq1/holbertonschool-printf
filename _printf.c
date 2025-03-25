#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"


int _printf(const char *format, ...)
{
  int i = 0;
    char *str;
    va_list arg;
    int printed = 0;/*to start calculating how many chars printed*/

    if (format == NULL)/*checking if format is NULL and terminates if so*/
    {
        write(1, "failed", 6);
	printed++;
        return (0);
    }
    va_start(arg, format);/*initilizing the varadiac funtion.*/
    while (format[i]) /*looping through the format string.*/
    {
        if (format[i] == '%' && format[i + 1] == 'c')/*if % is found and c after it, we can print the char*/
        {
            char c = va_arg(arg, int); /*assigning ecah arg to c.*/
            write(1, &c, 1 ); /*printing out each charachter*/
	    printed++;
            i = i + 2 ;/*to skip the (%c) in thr formatt so we dont print them and look for thr next(%)*/
            continue;
        }
        if (format[i] == '%' && format[i + 1] == 's')/* if % is follwed by a S, we will print a string*/
        {
            str = va_arg(arg, char *);
	    if (str == NULL)
		    str = "(null)";
            printed = printed + print_string(str);/*printing string funtion.*/
            i = i + 2;
            continue;
        }
	if (format[i] == '%' && format[i+1] == '%') /*check for "%%"*/
        {
            write(1, "%", 1); /*write '%' to stdout*/
            printed++; /*increment the printed character counter*/
            i+=2; /*skip "%%" in the format string */
            continue; /*move to the next character*/
        }
        write(1, &format[i], 1); /*print regular characters*/
        printed++;
        i++;
    }
	va_end(arg); /*clean up the argument list*/
   	return(printed);
}
