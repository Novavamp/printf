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

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0' || format_specifier(format[i], args) == -1)
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
        default:
            _putchar('%');
            _putchar(c);
            count += 2;
            break;
    }

    return (count);
}

int print_number(int num)
{
    int count = 0;

    if (num == 0)
    {
        _putchar('0');
        count++;
    }
    else if (num < 0)
    {
        _putchar('-');
        count++;
        num = -num;
    }

    if (num / 10)
        count += print_number(num / 10);

    _putchar((num % 10) + '0');
    count++;

    return count;
}

int _putchar(char c)
{
    return putchar(c);
}

int _print_char(va_list args)
{
    char ch = va_arg(args, char);
    return _putchar(ch);
}

int _print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str == NULL)
        return (-1);

    while (*str)
    {
        _putchar(*str);
        count++;
        str++;
    }

    return count;
}

int _print_int(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;

    if (num < 0)
    {
        _putchar('-');
        count++;
        num = (unsigned int)-num;
    }

    count += print_number(num);

    return count;
}

int _print_unsigned_int(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    count += print_number(num);

    return count;
}

int _print_octal(int num)
{
    int count = 0;

    while (num)
    {
        count += 1;
        _putchar((num % 8) + '0');
        num //= 8;
    }

    return count;
}

int _print_hex_lower(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    count += print_hex(num, 'a');

    return count;
}

int _print_hex_upper(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    count

 += print_hex(num, 'A');

    return count;
}

int _print_float(va_list args)
{
    double num = va_arg(args, double);
    int count = 0;

    count += _print_float(num);

    return count;
}

int _print_scientific(va_list args)
{
    double num = va_arg(args, double);
    int count = 0;

    count += _print_scientific(num);

    return count;
}

int _print_pointer(va_list args)
{
    void *ptr = va_arg(args, void *);
    int count = 0;

    count += _putchar('0');
    count += _putchar('x');
    count += print_hex((unsigned long int)ptr, 'a');

    return count;
}

int print_number(long int num)
{
    int count = 0;

    if (num == 0)
    {
        _putchar('0');
        count++;
    }
    else if (num < 0)
    {
        _putchar('-');
        count++;
        num = -num;
    }

    if (num / 10)
        count += print_number(num / 10);

    _putchar((num % 10) + '0');
    count++;

    return count;
}

int _print_octal(unsigned int num)
{
    int count = 0;

    if (num / 8)
        count += _print_octal(num / 8);

    _putchar((num % 8) + '0');
    count++;

    return count;
}

int print_hex(unsigned int num, char base)
{
    int count = 0;
    int remainder;

    if (num / 16)
        count += print_hex(num / 16, base);

    remainder = num % 16;

    if (remainder < 10)
        _putchar(remainder + '0');
    else
        _putchar(remainder - 10 + base);

    count++;

    return count;
}

int print_float(double num)
{
    int count = 0;
    char buffer[32];

    sprintf(buffer, "%f", num);

    char *ptr = buffer;
    while (*ptr)
    {
        _putchar(*ptr);
        count++;
        ptr++;
    }

    return count;
}

int print_scientific(double num)
{
    int count = 0;
    char buffer[32];

    sprintf(buffer, "%e", num);

    char *ptr = buffer;
    while (*ptr)
    {
        _putchar(*ptr);
        count++;
        ptr++;
    }

    return count;
}
