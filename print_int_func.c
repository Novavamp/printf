#include "main.h"

/**
 * print_int - Prints an integer value from a va_list
 *
 * @list: A va_list containing the integer value to be printed
 *
 * Return: The number of characters to be printed
 */
int print_int(va_list list)
{
    int number = va_arg(list, int);
    int len = 0;
    unsigned int digits = (number < 0) ? -number : number;

    if (number < 0)
    {
        putchar('-');
        len++;
    }
    else if (number == 0)
    {
        putchar('0');
        return (1);
    }

    len += int_helper(digits);
    return (len);
}

/**
 * int_helper - Recursively calculates the number of digits in an unsigned integer
 *
 * @value: The unsigned integer value to calculate digits for
 *
 * Return: The number of digits in the unsigned integer
 */
int int_helper(unsigned int value)
{
    int len;

    if (value == 0)
    {
        return (0);
    }

    len = (1 + int_helper(value / 10));
    putchar(value % 10 + '0');
    return (len);
}
