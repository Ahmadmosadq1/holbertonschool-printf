#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int print_string(char *format)
{
    int j=0;
    
    while (format[j] != '\0')
    {
    	j++;
    }
    write(1, format, j);
    return(j);
}
