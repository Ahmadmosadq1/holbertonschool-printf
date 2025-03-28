#ifndef MAIN_H
#define MAIN_H
int _printf(const char *format, ...);
void print_string(char *format, int *i, char *buffer, int buff_count);
void print_char(char c, int *i, char *buffer, int buff_count);
void print_number(int n, int *i, char *buffer, int buff_count);
void print_binary(unsigned int n, int *i ,char *buffer, int buff_count);
void print_unsigned(unsigned int n, int *i ,char *buffer, int buff_count);
void print_octal(unsigned int n, int *i, char *buffer, int buff_count);
void print_hexa(unsigned int n, char format, int *i, char *buffer, int buff_count);
#endif

