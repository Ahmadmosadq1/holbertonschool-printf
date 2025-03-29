#ifndef MAIN_H
#define MAIN_H
int _printf(const char *format, ...);
void print_string(char *format, int *i, char *buffer, int *buff_count, int *total);
void print_char(char c, int *i, char *buffer, int *buff_count, int *total);
void print_number(int n, int *i, char *buffer, int *buff_count, int *total);
void print_binary(unsigned int n, int *i ,char *buffer, int *buff_count, int *total);
void print_unsigned(unsigned int n, int *i ,char *buffer, int *buff_count, int *total);
void print_octal(unsigned int n, int *i, char *buffer, int *buff_count, int *total);
void print_hexa(unsigned int n, char format, int *i, char *buffer, int *buff_count, int *total);
void buff_checker(char *buffer, int *buff_count, int *total);
#endif

