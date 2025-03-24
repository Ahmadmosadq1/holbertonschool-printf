#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
void print_string(const char *format)
{
    int j;
    for (j = 0; format[j] != '\0'; j++)
        write(1, &format[j], 1);
}
