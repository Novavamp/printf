#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

/**
 * struct print_format - format specifier and print function mapping
 *
 * @specifier: format specifier character
 * @print: function pointer to the corresponding print function
 *
 * Description: This structure is used to associate format specifiers (e.g., %d or %s)
 * with their respective print functions. The @specifier field represents the format specifier,
 * and @print is a function pointer that points to the corresponding print function.
 */
typedef struct print_format
{
  char specifier;
	int (*print)(va_list list);
} prt;

int _printf(const char *format, ...);
int print_str(va_list list);
int binary_helper(int value);
int print_mod(va_list list);
int print_char(va_list list);
int print_int(va_list list);
int int_helper(unsigned int value);
int print_binary(va_list list);
int print_unsigned(va_list list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_hex_upper(va_list list);

#endif
