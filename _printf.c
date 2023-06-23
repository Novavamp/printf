#include "main.h"
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break;
            switch (*format)
            {
                case 'c':
                    printed_chars += _print_char(va_arg(args, int));
                    break;
                case 's':
                    printed_chars += _print_string(va_arg(args, char *));
                    break;
                case 'd':
                case 'i':
                    printed_chars += _print_int(va_arg(args, int));
                    break;
                case 'u':
                    printed_chars += _print_unsigned_int(va_arg(args, unsigned int));
                    break;
                case 'o':
                    printed_chars += _print_octal(va_arg(args, unsigned int));
                    break;
                case 'x':
                    printed_chars += _print_hex_lower(va_arg(args, unsigned int));
                    break;
                case 'X':
                    printed_chars += _print_hex_upper(va_arg(args, unsigned int));
                    break;
                case 'f':
                    printed_chars += _print_float(va_arg(args, double));
                    break;
                case 'e':
                    printed_chars += _print_scientific(va_arg(args, double));
                    break;
                case 'p':
                    printed_chars += _print_pointer(va_arg(args, void *));
                    break;
                case 'l':
                    format++;
                    switch (*format)
                    {
                        case 'd':
                        case 'i':
                            printed_chars += _print_long(va_arg(args, long));
                            break;
                        case 'u':
                            printed_chars += _print_unsigned_long(va_arg(args, unsigned long));
                            break;
                        case 'o':
                            printed_chars += _print_octal_long(va_arg(args, unsigned long));
                            break;
                        case 'x':
                            printed_chars += _print_hex_lower_long(va_arg(args, unsigned long));
                            break;
                        case 'X':
                            printed_chars += _print_hex_upper_long(va_arg(args, unsigned long));
                            break;
                        default:
                            _putchar('%');
                            _putchar('l');
                            printed_chars += 2;
                            break;
                    }
                    break;
                case 'L':
                    format++;
                    switch (*format)
                    {
                        case 'f':
                            printed_chars += _print_long_double(va_arg(args, long double));
                            break;
                        default:
                            _putchar('%');
                            _putchar('L');
                            printed_chars += 2;
                            break;
                    }
                    break;
                case '%':
                    _putchar('%');
                    printed_chars++;
                    break;
                default:
                    _putchar('%');
                    _putchar(*format);
                    printed_chars += 2;
                    break;
            }
        }
        else
        {
            _putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(args);

    return printed_chars;
}
