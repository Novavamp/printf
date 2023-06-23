#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);

int _putchar(char c);
int _print_char(va_list args);
int _print_string(va_list args);
int _print_int(va_list args);
int _print_unsigned_int(va_list args);
int _print_octal(va_list args);
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
