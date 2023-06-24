#include <stdio.h>
#include <stdarg.h>
#include "main.h"

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

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    int i = 0;

    va_start(args, format);

    if (format == NULL)
        return (-1);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                return (-1);

            switch (format[i])
            {
                case 'c':
                    printed_chars += _print_char(args);
                    break;
                case 's':
                    printed_chars += _print_string(args);
                    break;
                case 'd':
                case 'i':
                    printed_chars += _print_int(args);
                    break;
                case 'u':
                    printed_chars += _print_unsigned_int(args);
                    break;
                case 'o':
                    printed_chars += _print_octal(args);
                    break;
                case 'x':
                    printed_chars += _print_hex_lower(args);
                    break;
                case 'X':
                    printed_chars += _print_hex_upper(args);
                    break;
                case 'f':
                    printed_chars += _print_float(args);
                    break;
                case 'e':
                    printed_chars += _print_scientific(args);
                    break;
                case 'p':
                    printed_chars += _print_pointer(args);
                    break;
                case 'l':
                    i++;
                    if (format[i] == 'd' || format[i] == 'i')
                        printed_chars += _print_long(args);
                    else if (format[i] == 'u')
                        printed_chars += _print_unsigned_long(args);
                    else if (format[i] == 'o')
                        printed_chars += _print_octal_long(args);
                    else if (format[i] == 'x')
                        printed_chars += _print_hex_lower_long(args);
                    else if (format[i] == 'X')
                        printed_chars += _print_hex_upper_long(args);
                    else if (format[i] == 'l')
                    {
                        i++;
                        if (format[i] == 'd' || format[i] == 'i')
                            printed_chars += _print_long_long(args);
                        else if (format[i] == 'u')
                            printed_chars += _print_unsigned_long_long(args);
                        else if (format[i] == 'o')
                            printed_chars += _print_octal_long_long(args);
                        else if (format[i] == 'x')
                            printed_chars += _print_hex_lower_long_long(args);
                        else if (format[i] == 'X')
                            printed_chars += _print_hex_upper_long_long(args);
                        else if (format[i] == 'f')
                            printed_chars += _print_long_double(args);
                        else
                            _putchar('%'), _putchar('l'), printed_chars += 2;
                    }
                    else
                        _putchar('%'), _putchar('l'), printed_chars += 2;
                    break;
                default:
                    _putchar('%'), _putchar(format[i]), printed_chars += 2;
                    break;
            }
        }
        else
        {
            _putchar(format[i]);
            printed_chars++;
        }

        i++;
    }

    va_end(args);

    return (printed_chars);
}
