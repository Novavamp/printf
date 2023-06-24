#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);

int _putchar(char c);
int _getchar(void);

int print_binary(va_list list);
int binary_helper(unsigned int value);
int print_number_base(int num, int base);
int print_number(int num);
int format_specifier(char c, va_list args);
int _print_char(va_list args);
int _print_string(char *str);
int _print_int(va_list args);
int _print_unsigned_int(va_list args);
int _print_octal(va_list args);
int _print_hex(va_list args);
int print_hex(unsigned int num, int base, const char *digits);
int _print_hex_lower(va_list args);
int _print_hex_upper(va_list args);
int _print_float(va_list args);
int _print_scientific(va_list args);
int _print_pointer(va_list args);
int _print_long(va_list args);
int _print_unsigned_long(va_list args);
int _print_octal_long(va_list args);
int _print_hex_lower_long(va_list args);
int _print_hex_upper_long(va_list args);
int _print_long_long(va_list args);
int _print_unsigned_long_long(va_list args);
int _print_octal_long_long(va_list args);
int _print_hex_lower_long_long(va_list args);
int _print_hex_upper_long_long(va_list args);
int _print_long_double(va_list args);

#endif /* MAIN_H */
