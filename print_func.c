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
    unsigned int number = va_arg(list, unsigned int);

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
int binary_helper(unsigned int value)
{
    int len = 0;

    if (value == 0)
        return (0);

    len = (1 + binary_helper(value / 2));
    putchar((value % 2) + '0');
    return (len);
}

/**
 * print_unsigned - Prints an unsigned decimal number.
 * @list: A va_list containing the unsigned number to print.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(va_list list)
{
    unsigned int number = va_arg(list, unsigned int);

    return (print_uint_helper(number, 10));
}

/**
 * print_octal - Prints an unsigned int in octal format.
 * @list: A va_list containing the unsigned int to print.
 *
 * Return: The number of characters printed.
 */
int print_octal(va_list list)
{
    unsigned int number = va_arg(list, unsigned int);

    return (print_uint_helper(number, 8));
}

/**
 * print_hex - Prints an unsigned int in lowercase hexadecimal format.
 * @list: A va_list containing the unsigned int to print.
 *
 * Return: The number of characters printed.
 */
int print_hex(va_list list)
{
    unsigned int number = va_arg(list, unsigned int);

    return (print_uint_helper(number, 16));
}

/**
 * print_hex_upper - Prints an unsigned int in uppercase hexadecimal format.
 * @list: A va_list containing the unsigned int to print.
 *
 * Return: The number of characters printed.
 */
int print_hex_upper(va_list list)
{
    unsigned int number = va_arg(list, unsigned int);

    return (print_uint_upper_helper(number, 16));
}

/**
 * print_uint_helper - Helper function to print an unsigned int with a given base.
 * @number: The unsigned int to print.
 * @base: The base to use for printing (e.g., 10 for decimal, 8 for octal, 16 for hexadecimal).
 *
 * Return: The number of characters printed.
 */
int print_uint_helper(unsigned int number, int base)
{
    unsigned int value = number;
    int len = 0;

    if (value == 0)
    {
        putchar('0');
        return (1);
    }

    while (value > 0)
    {
        len++;
        value /= base;
    }

    print_uint_recursive(number, base);
    return (len);
}

/**
 * print_uint_recursive - Recursively prints the digits of an unsigned int in a given base.
 * @number: The unsigned int to print.
 * @base: The base to use for printing (e.g., 10 for decimal, 8 for octal, 16 for hexadecimal).
 */
void print_uint_recursive(unsigned int number, int base)
{
    unsigned int digit = number % base;
    unsigned int quotient = number / base;

    if (quotient > 0)
    {
        print_uint_recursive(quotient, base);
    }

    if (digit < 10)
    {
        putchar(digit + '0');
    }
    else
    {
        putchar(digit - 10 + 'a');
    }
}

/**
 * print_uint_upper_helper - Helper function to print an unsigned int in uppercase hexadecimal format.
 * @number: The unsigned int to print.
 * @base: The base to use for printing (16 for hexadecimal).
 *
 * Return: The number of characters printed.
 */
int print_uint_upper_helper(unsigned int number, int base)
{
    unsigned int value = number;
    int len = 0;

    if (value == 0)
    {
        putchar('0');
        return (1);
    }

    while (value > 0)
    {
        len++;
        value /= base;
    }

    print_uint_upper_recursive(number, base);
    return (len);
}

/**
 * print_uint_upper_recursive - Recursively prints the digits of an unsigned int in uppercase hexadecimal format.
 * @number: The unsigned int to print.
 * @base: The base to use for printing (16 for hexadecimal).
 */
void print_uint_upper_recursive(unsigned int number, int base)
{
    unsigned int digit = number % base;
    unsigned int quotient = number / base;

    if (quotient > 0)
    {
        print_uint_upper_recursive(quotient, base);
    }

    if (digit < 10)
    {
        putchar(digit + '0');
    }
    else
    {
        putchar(digit - 10 + 'A');
    }
}
