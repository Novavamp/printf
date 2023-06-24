#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    int i = 0;

    va_start(args, format);

    if (format == NULL)
        return (-1);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                return (-1);
            printed_chars += format_specifier(format[i], args);
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

int format_specifier(char c, va_list args)
{
    int count = 0;

    switch (c)
    {
        case 'c':
            count += _print_char(args);
            break;
        case 's':
            count += _print_string(args);
            break;
        case 'i':
        case 'd':
            count += _print_int(args);
            break;
        case 'u':
            count += _print_unsigned_int(args);
            break;
        case 'o':
            count += _print_octal(args);
            break;
        case 'x':
            count += _print_hex_lower(args);
            break;
        case 'X':
            count += _print_hex_upper(args);
            break;
        case 'f':
            count += _print_float(args);
            break;
        case 'e':
            count += _print_scientific(args);
            break;
        case 'p':
            count += _print_pointer(args);
            break;
        case 'l':
            count += handle_long_specifier(args);
            break;
        case 'L':
            count += handle_long_double_specifier(args);
            break;
        default:
            _putchar('%');
            _putchar(c);
            count += 2;
            break;
    }

    return (count);
}

int _putchar(char c)
{
    return (putchar(c));
}

int _print_char(va_list args)
{
    char ch = va_arg(args, int);
    return (_putchar(ch));
}

int _print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str == NULL)
        str = "(null)";

    while (*str)
    {
        _putchar(*str);
        count++;
        str++;
    }

    return (count);
}

/* Implement the remaining _print_* functions here */

int _print_int(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;

    if (num < 0)
    {
        _putchar('-');
        count++;
        num = -num;
    }

    count += print_number(num);

    return (count);
}

int _print_unsigned_int(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    count += print_number(num);

    return (count);
}

int _print_octal(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    count += print_octal(num);

    return (count);
}

int _print_hex_lower(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    count += print_hex(num, 'a');

    return (count);
}

int _print_hex_upper(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    count += print_hex(num, 'A');

    return (count);
}

int _print_float(va_list args)
{
    double num = va_arg(args, double);
    int count = 0;

    count += print_float(num);

    return (count);
}

int _print_scientific(va_list args)
{
    double num = va_arg(args, double);
    int count = 0;

    count += print_scientific(num);

    return (count);
}

int _print_pointer(va_list args)
{
    void *ptr = va_arg(args, void *);
    int count = 0;

    count += print_pointer(ptr);

    return (count);
}

int _print_long(va_list args)
{
    long num = va_arg(args, long);
    int count = 0;

    if (num < 0)
    {
        _putchar('-');
        count++;
        num = -num;
    }

    count += print_number(num);

    return (count);
}

int _print_unsigned_long(va_list args)
{
    unsigned long num = va_arg(args, unsigned long);
    int count = 0;

    count += print_number(num);

    return (count);
}

int _print_octal_long(va_list args)
{
    unsigned long num = va_arg(args, unsigned long);
    int count = 0;

    count += print_octal(num);

    return (count);
}

int _print_hex_lower_long(va_list args)
{
    unsigned long num = va_arg(args, unsigned long);
    int count = 0;

    count += print_hex(num, 'a');

    return (count);
}

int _print_hex_upper_long(va_list args)
{
    unsigned long num = va_arg(args, unsigned long);
    int count = 0;

    count += print_hex(num, 'A');

    return (count);
}

int _print_long_long(va_list args)
{
    long long num = va_arg(args, long long);
    int count = 0;

    if (num < 0)
    {
        _putchar('-');
        count++;
        num = -num;
    }

    count += print_number(num);

    return (count);
}

int _print_unsigned_long_long(va_list args)
{
    unsigned long long num = va_arg(args, unsigned long long);
    int count = 0;

    count += print_number(num);

    return (count);
}

int _print_octal_long_long(va_list args)
{
    unsigned long long num = va_arg(args, unsigned long long);
    int count = 0;

    count += print_octal(num);

    return (count);
}

int _print_hex_lower_long_long(va_list args)
{
    unsigned long long num = va_arg(args, unsigned long long);
    int count = 0;

    count += print_hex(num, 'a');

    return (count);
}

int _print_hex_upper_long_long(va_list args)
{
    unsigned long long num = va_arg(args, unsigned long long);
    int count = 0;

    count += print_hex(num, 'A');

    return (count);
}

int _print_long_double(va_list args)
{
    long double num = va_arg(args, long double);
    int count = 0;

    count += print_long_double(num);

    return (count);
}

int print_number(unsigned long long num)
{
    unsigned long long divisor = 1;
    int count = 0;

    while (num / divisor > 9)
        divisor *= 10;

    while (divisor != 0)
    {
        _putchar((num / divisor) + '0');
        count++;
        num %= divisor;
        divisor /= 10;
    }

    return (count);
}

int print_octal(unsigned long num)
{
    unsigned long octal[32];
    int i = 0;
    int count = 0;

    if (num == 0)
    {
        _putchar('0');
        return (1);
    }

    while (num != 0)
    {
        octal[i] = num % 8;
        num /= 8;
        i++;
    }

    for (i -= 1; i >= 0; i--)
    {
        _putchar(octal[i] + '0');
        count++;
    }

    return (count);
}

int print_hex(unsigned long num, char hex_case)
{
    char hex[32];
    int i = 0;
    int count = 0;

    if (num == 0)
    {
        _putchar('0');
        return (1);
    }

    while (num != 0)
    {
        int remainder = num % 16;

        if (remainder < 10)
            hex[i] = remainder + '0';
        else
            hex[i] = remainder - 10 + hex_case;

        num /= 16;
        i++;
    }

    for (i -= 1; i >= 0; i--)
    {
        _putchar(hex[i]);
        count++;
    }

    return (count);
}

int print_float(double num)
{
    int count = 0;
    int integer = (int)num;
    double fraction = num - integer;

    if (num < 0)
    {
        _putchar('-');
        count++;
        integer = -integer;
        fraction = -fraction;
    }

    count += print_number(integer);
    _putchar('.');
    count++;

    for (int i = 0; i < 6; i++)
    {
        fraction *= 10;
        int digit = (int)fraction;
        _putchar(digit + '0');
        count++;
        fraction -= digit;
    }

    return (count);
}

int print_scientific(double num)
{
    int count = 0;
    int integer = (int)num;
    double fraction = num - integer;

    if (num < 0)
    {
        _putchar('-');
        count++;
        integer = -integer;
        fraction = -fraction;
    }

    count += print_number(integer);
    _putchar('.');
    count++;

    for (int i = 0; i < 6; i++)
    {
        fraction *= 10;
        int digit = (int)fraction;
        _putchar(digit + '0');
        count++;
        fraction -= digit;
    }

    _putchar('e');
    count++;

    if (num >= 1)
    {
        _putchar('+');
        count++;
    }
    else
    {
        _putchar('-');
        count++;
    }

    int exponent = 0;

    while (num >= 10 || num <= -10)
    {
        if (num >= 10)
        {
            num /= 10;
            exponent++;
        }
        else
        {
            num *= 10;
            exponent--;
        }
    }

    count += print_number(exponent);

    return (count);
}

int print_pointer(void *ptr)
{
    unsigned long long num = (unsigned long long)ptr;
    int count = 0;

    _putchar('0');
    _putchar('x');
    count += 2;

    count += print_hex(num, 'a');

    return (count);
}

int handle_long_specifier(va_list args)
{
    char c = _getchar();
    int count = 0;

    if (c == 'd' || c == 'i')
    {
        long num = va_arg(args, long);

        if (num < 0)
        {
            _putchar('-');
            count++;
            num = -num;
        }

        count += print_number(num);
    }
    else if (c == 'u')
    {
        unsigned long num = va_arg(args, unsigned long);
        count += print_number(num);
    }
    else if (c == 'o')
    {
        unsigned long num = va_arg(args, unsigned long);
        count += print_octal(num);
    }
    else if (c == 'x')
    {
        unsigned long num = va_arg(args, unsigned long);
        count += print_hex(num, 'a');
    }
    else if (c == 'X')
    {
        unsigned long num = va_arg(args, unsigned long);
        count += print_hex(num, 'A');
    }

    return (count);
}

int print_long_double(long double num)
{
    int count = 0;
    int integer = (int)num;
    double fraction = num - integer;

    if (num < 0)
    {
        _putchar('-');
        count++;
        integer = -integer;
        fraction = -fraction;
    }

    count += print_number(integer);
    _putchar('.');
    count++;

    for (int i = 0; i < 6; i++)
    {
        fraction *= 10;
        int digit = (int)fraction;
        _putchar(digit + '0');
        count++;
        fraction -= digit;
    }

    return (count);
}
