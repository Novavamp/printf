#include "main.h"
#include <stddef.h>

/**
 * print_char - Prints a single character.
 * @list: va_list containing the character to be printed.
 *
 * Return: The number of characters printed (always 1).
 */
int print_char(va_list list)
{
    char ch = va_arg(list, int);

    putchar(ch);
    return (1);
}

/**
 * print_str - Prints a null-terminated string.
 * @list: va_list containing the string to be printed.
 *
 * Return: The number of characters printed.
 */
int print_str(va_list list)
{
    char *str = va_arg(list, char *);
    int i;

    if (str == NULL)
    {
        str = "(null)";
    }

    for (i = 0; str[i]; i++)
    {
        putchar(str[i]);
    }

    return (i);
}

/**
 * print_mod - Prints a percent symbol.
 * @list: Unused.
 *
 * Return: The number of characters printed (always 1).
 */
int print_mod(__attribute__((unused)) va_list list)
{
    putchar('%');
    return (1);
}

/**
 * print_binary - Prints the binary representation of an unsigned int.
 * @list: A va_list containing the unsigned int to print.
 *
 * Return: The number of characters printed.
 */
int print_binary(va_list list)
{
    int number = va_arg(list, int);

    if (number == 0)
    {
        putchar('0');
        return (1);
    }
    else if (number > 0)
        return (binary_helper(number));

    return (0);
}

/**
 * binary_helper - Converts an integer to its binary representation.
 * @value: The integer to convert.
 *
 * Return: The number of characters printed.
 */
int binary_helper(int value)
{
    int len = 0;

    if (value == 0)
        return (0);

    len = (1 + binary_helper(value / 2));
    putchar((value % 2) + '0');
    return (len);
}
