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
    unsigned int num;
	
    switch (c)
    {
        case 'c':
            count += _print_char(args);
            break;
        case 's':
        {
            char *str = va_arg(args, char *);
            count += _print_string(str);
            break;
        }
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
        case 'b':
            num = va_arg(args, unsigned int);
            count += binary_helper(num);
            break;
        default:
            _putchar('%');
            _putchar(c);
            count += 2;
            break;
    }

    return count;
}

int print_binary(va_list list)
{
    unsigned int number = va_arg(list, unsigned int);
    int count = 0;

    if (number == 0)
    {
        putchar('0');
        return 1;
    }

    unsigned int mask = 1 << ((sizeof(unsigned int) * 8) - 1);
    int foundFirstOne = 0;

    while (mask > 0)
    {
        if ((number & mask) != 0)
        {
            foundFirstOne = 1;
            putchar('1');
            count++;
        }
        else if (foundFirstOne)
        {
            putchar('0');
            count++;
        }

        mask >>= 1;
    }

    return count;
}

int binary_helper(unsigned int value)
{
    int len = 0;

    if (value == 0)
        return 0;

    len = (1 + binary_helper(value / 2));
    _putchar((value % 2) + '0');
    return len;
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
    int ch = va_arg(args, int);
    return _putchar(ch);
}

int _print_string(char *str)
{
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

int _print_hex_lower(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    
    count += print_hex(num, 16, "0123456789abcdef");

    return count;
}

int _print_hex_upper(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    count += print_hex(num, 16, "0123456789ABCDEF");

    return count;
}

int _print_octal(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    count += print_hex(num, 8, "01234567");

    return count;
}

int print_hex(unsigned int num, int base, const char *digits)
{
    int count = 0;

    if (num / base)
        count += print_hex(num / base, base, digits);

    _putchar(digits[num % base]);
    count++;

    return count;
}

int _print_float(va_list args)
{
    double num = va_arg(args, double);
    int count = 0;
    char buffer[50];
    sprintf(buffer, "%f", num);

    count += _print_string(buffer);

    return count;
}

int _print_scientific(va_list args)
{
    double num = va_arg(args, double);
    int count = 0;
    char buffer[50];
    sprintf(buffer, "%e", num);

    count += _print_string(buffer);

    return count;
}

int _print_pointer(va_list args)
{
    void *ptr = va_arg(args, void *);
    int count = 0;
    char buffer[50];
    sprintf(buffer, "%p", ptr);

    count += _print_string(buffer);

    return count;
}
