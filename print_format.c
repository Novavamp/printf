#include "main.h"

/**
 * _printf - prints with specific formats for different data types
 * @format: a string of format specifiers for the data to be printed
 * @...: variable number of arguments that correspond to the format specifiers
 * Return: the total number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list list;
    int len = 0, i = 0, j, array_len;
    prt format_funcs[] = {
        {'c', print_char},
        {'s', print_str},
        {'%', print_mod},
        {'d', print_int},
        {'i', print_int},
        {'b', print_binary},
        {'u', print_unsigned},
        {'o', print_octal},
        {'x', print_hex},
        {'X', print_hex_upper},
    };

    if (!format || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    va_start(list, format);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            putchar(format[i]);
            len++;
        }
        else
        {
            i++;
            array_len = sizeof(format_funcs) / sizeof(format_funcs[0]);
            for (j = 0; j < array_len; j++)
            {
                if (format[i] == format_funcs[j].specifier)
                {
                    len += format_funcs[j].print(list);
                    break;
                }
            }

            if (format[i] != format_funcs[j].specifier)
            {
                putchar('%');
                putchar(format[i]);
                len += 2;
            }
        }
        i++;
    }

    va_end(list);
    return (len);
}
