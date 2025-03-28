#ifndef MAIN_H
#define MAIN_H
int _printf(const char *format, ...);
int print_string(char *format, int *i);
int print_char(char c, int *i);
int print_number(int n, int *i);
int print_binary(unsigned int n, int *i);
int print_unsigned(unsigned int n, int *i);
int print_octal(unsigned int n, int *i);
int print_hexa(unsigned int n, char format, int *i);
int print_nonPrintable(char *str, int *i);
#endif

