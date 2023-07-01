#include "main.h"

/**
 * print_str - Prints the string with special handling for non-printable characters
 * @args: Variable argument list
 * Return: Number of characters printed
 */
int print_str(va_list args)
{
    int length = 0;
    char *str = va_arg(args, char *);

    if (str == NULL)
    {
        length += _printf("(null)");
    }
    else
    {
        while (*str)
        {
            if (*str >= 32 && *str < 127)
            {
                putchar(*str);
                length++;
            }
            else
            {
                putchar('\\');
                putchar('x');
                length += 2;
                length += _printf("%02X", (unsigned char)*str);
            }
            str++;
        }
    }

    return length;
}

/**
 * _printf - Prints formatted output
 * @format: A string containing format specifiers
 * @...: Variadic arguments corresponding to the format specifiers
 * Return: The total number of characters printed
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
        {'S', print_str},
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

            if (j == array_length)
            {
                putchar('%');
                putchar(format[i]);
                length += 2;
            }
        }

        i++;
    }

    va_end(args);

    return length;
}
