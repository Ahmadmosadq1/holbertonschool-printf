#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int print_string(char *format)
{
    int j = 0;
    if (format== NULL)
	    format = "(null)";
    
    while (format[j] != '\0')
    {
    	j++;
    }
    write(1, format, j);
    return(j);
}

void print_char(char c, int * i)
{
	write(1, &c, 1);
	*i += 2;
}

