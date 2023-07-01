#include "main.h"

/**
 * _printf - prints formatted output
 * @format: a string containing format specifiers
 * @...: variadic arguments corresponding to the format specifiers
 *
 * Return: the total number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int length = 0, i = 0, j, array_length;
    prt format_functions[] = {
        {'c', print_char},
        {'s', print_str},
        {'%', print_mod},
        {'d', print_int},
        {'i', print_int},
        {'b', print_binary},
    };

    if (!format || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            putchar(format[i]);
            length++;
        }
        else
        {
            i++;
            array_length = sizeof(format_functions) / sizeof(format_functions[0]);
            for (j = 0; j < array_length; j++)
            {
                if (format[i] == format_functions[j].specifier)
                {
                    length += format_functions[j].print(args);
                    break;
                }
            }

            if (format[i] != format_functions[j].specifier)
            {
                putchar(format[--i]);
                length++;
            }
        }

        i++;
    }

    va_end(args);

    return (length);
}
