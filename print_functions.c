#include "main.h"
#include <stdio.h>
#include <math.h>

int _print_char(va_list args)
{
    int c = va_arg(args, int);
    _putchar(c);
    return 1;
}

int _print_string(va_list args)
{
    char *str = va_arg(args, char*);
    if (str == NULL)
        str = "(null)";
    int printed_chars = 0;
    while (*str != '\0')
    {
        _putchar(*str);
        printed_chars++;
        str++;
    }
    return printed_chars;
}

int _print_int(va_list args)
{
    int num = va_arg(args, int);
    int printed_chars = 0;

    if (num < 0)
    {
        _putchar('-');
        printed_chars++;
        num = -num;
    }

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_digits = 0;
    int temp = num;
    while (temp != 0)
    {
        temp /= 10;
        num_digits++;
    }

    char digits[num_digits];
    int i = num_digits - 1;

    while (num != 0)
    {
        digits[i] = num % 10 + '0';
        num /= 10;
        i--;
    }

    for (int j = 0; j < num_digits; j++)
    {
        _putchar(digits[j]);
        printed_chars++;
    }

    return printed_chars;
}

int _print_unsigned(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int printed_chars = 0;

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_digits = 0;
    unsigned int temp = num;
    while (temp != 0)
    {
        temp /= 10;
        num_digits++;
    }

    char digits[num_digits];
    int i = num_digits - 1;

    while (num != 0)
    {
        digits[i] = num % 10 + '0';
        num /= 10;
        i--;
    }

    for (int j = 0; j < num_digits; j++)
    {
        _putchar(digits[j]);
        printed_chars++;
    }

    return printed_chars;
}

int _print_octal(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int printed_chars = 0;

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_digits = 0;
    unsigned int temp = num;
    while (temp != 0)
    {
        temp /= 8;
        num_digits++;
    }

    char digits[num_digits];
    int i = num_digits - 1;

    while (num != 0)
    {
        digits[i] = num % 8 + '0';
        num /= 8;
        i--;
    }

    for (int j = 0; j < num_digits; j++)
    {
        _putchar(digits[j]);
        printed_chars++;
    }

    return printed_chars;
}

int _print_hex_lower(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int printed_chars = 0;

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_digits = 0;
    unsigned int temp = num;
    while (temp != 0)
    {
        temp /= 16;
        num_digits++;
    }

    char digits[num_digits];
    int i = num_digits - 1;

    while (num != 0)
    {
        int remainder = num % 16;
        if (remainder < 10)
            digits[i] = remainder + '0';
        else
            digits[i] = remainder - 10 + 'a';
        num /= 16;
        i--;
    }

    for (int j = 0; j < num_digits; j++)
    {
        _putchar(digits[j]);
        printed_chars++;
    }

    return printed_chars;
}

int _print_hex_upper(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int printed_chars = 0;

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_digits = 0;
    unsigned int temp = num;
    while (temp != 0)
    {
        temp /= 16;
        num_digits++;
    }

    char digits[num_digits];
    int i = num_digits - 1;

    while (num != 0)
    {
        int remainder = num % 16;
        if (remainder < 10)
            digits[i] = remainder + '0';
        else
            digits[i] = remainder - 10 + 'A';
        num /= 16;
        i--;
    }

    for (int j = 0; j < num_digits; j++)
    {
        _putchar(digits[j]);
        printed_chars++;
    }

    return printed_chars;
}

int _print_binary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int printed_chars = 0;

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_bits = 0;
    unsigned int temp = num;
    while (temp != 0)
    {
        temp >>= 1;
        num_bits++;
    }

    char bits[num_bits];
    int i = num_bits - 1;

    while (num != 0)
    {
        bits[i] = (num & 1) + '0';
        num >>= 1;
        i--;
    }

    for (int j = 0; j < num_bits; j++)
    {
        _putchar(bits[j]);
        printed_chars++;
    }

    return printed_chars;
}

int _print_float(va_list args)
{
    double num = va_arg(args, double);
    int printed_chars = 0;

    if (isnan(num) || isinf(num))
    {
        printed_chars += _print_string("nan");
        return printed_chars;
    }

    if (num < 0)
    {
        _putchar('-');
        printed_chars++;
        num = -num;
    }

    int integer_part = (int)num;
    double fractional_part = num - integer_part;

    printed_chars += _print_int(integer_part);

    _putchar('.');
    printed_chars++;

    int decimal_digits = 6; // Change as needed for desired precision
    double decimal_multiplier = pow(10, decimal_digits);

    int decimal_part = (int)(fractional_part * decimal_multiplier + 0.5);

    printed_chars += _print_int(decimal_part);

    return printed_chars;
}

int _print_scientific_notation(va_list args)
{
    double num = va_arg(args, double);
    int printed_chars = 0;

    if (isnan(num) || isinf(num))
    {
        printed_chars += _print_string("nan");
        return printed_chars;
    }

    if (num < 0)
    {
        _putchar('-');
        printed_chars++;
        num = -num;
    }

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int exponent = 0;
    if (num >= 1)
    {
        while (num >= 10)
        {
            num /= 10;
            exponent++;
        }
    }
    else
    {
        while (num < 1)
        {
            num *= 10;
            exponent--;
        }
    }

    printed_chars += _print_float(num);
    printed_chars += _putchar('e');
    printed_chars += _print_int(exponent);

    return printed_chars;
}

int _print_pointer(va_list args)
{
    void *ptr = va_arg(args, void *);
    int printed_chars = 0;

    printed_chars += _print_string("0x");
    unsigned long int address = (unsigned long int)ptr;
    printed_chars += _print_hex_lower(address);

    return printed_chars;
}

int _print_num_chars(va_list args)
{
    int *num_chars_ptr = va_arg(args, int *);
    *num_chars_ptr = total_printed_chars;
    return 0;
}

int _print_long(va_list args)
{
    long num = va_arg(args, long);
    int printed_chars = 0;

    if (num < 0)
    {
        _putchar('-');
        printed_chars++;
        num = -num;
    }

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_digits = 0;
    long temp = num;
    while (temp != 0)
    {
        temp /= 10;
        num_digits++;
    }

    char digits[num_digits];
    int i = num_digits - 1;

    while (num != 0)
    {
        digits[i] = num % 10 + '0';
        num /= 10;
        i--;
    }

    for (int j = 0; j < num_digits; j++)
    {
        _putchar(digits[j]);
        printed_chars++;
    }

    return printed_chars;
}

int _print_unsigned_long(va_list args)
{
    unsigned long num = va_arg(args, unsigned long);
    int printed_chars = 0;

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_digits = 0;
    unsigned long temp = num;
    while (temp != 0)
    {
        temp /= 10;
        num_digits++;
    }

    char digits[num_digits];
    int i = num_digits - 1;

    while (num != 0)
    {
        digits[i] = num % 10 + '0';
        num /= 10;
        i--;
    }

    for (int j = 0; j < num_digits; j++)
    {
        _putchar(digits[j]);
        printed_chars++;
    }

    return printed_chars;
}

int _print_octal_long(va_list args)
{
    unsigned long num = va_arg(args, unsigned long);
    int printed_chars = 0;

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_digits = 0;
    unsigned long temp = num;
    while (temp != 0)
    {
        temp /= 8;
        num_digits++;
    }

    char digits[num_digits];
    int i = num_digits - 1;

    while (num != 0)
    {
        digits[i] = num % 8 + '0';
        num /= 8;
        i--;
    }

    for (int j = 0; j < num_digits; j++)
    {
        _putchar(digits[j]);
        printed_chars++;
    }

    return printed_chars;
}

int _print_hex_lower_long(va_list args)
{
    unsigned long num = va_arg(args, unsigned long);
    int printed_chars = 0;

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_digits = 0;
    unsigned long temp = num;
    while (temp != 0)
    {
        temp /= 16;
        num_digits++;
    }

    char digits[num_digits];
    int i = num_digits - 1;

    while (num != 0)
    {
        int remainder = num % 16;
        if (remainder < 10)
            digits[i] = remainder + '0';
        else
            digits[i] = remainder - 10 + 'a';
        num /= 16;
        i--;
    }

    for (int j = 0; j < num_digits; j++)
    {
        _putchar(digits[j]);
        printed_chars++;
    }

    return printed_chars;
}

int _print_hex_upper_long(va_list args)
{
    unsigned long num = va_arg(args, unsigned long);
    int printed_chars = 0;

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_digits = 0;
    unsigned long temp = num;
    while (temp != 0)
    {
        temp /= 16;
        num_digits++;
    }

    char digits[num_digits];
    int i = num_digits - 1;

    while (num != 0)
    {
        int remainder = num % 16;
        if (remainder < 10)
            digits[i] = remainder + '0';
        else
            digits[i] = remainder - 10 + 'A';
        num /= 16;
        i--;
    }

    for (int j = 0; j < num_digits; j++)
    {
        _putchar(digits[j]);
        printed_chars++;
    }

    return printed_chars;
}

int _print_long_long(va_list args)
{
    long long num = va_arg(args, long long);
    int printed_chars = 0;

    if (num < 0)
    {
        _putchar('-');
        printed_chars++;
        num = -num;
    }

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_digits = 0;
    long long temp = num;
    while (temp != 0)
    {
        temp /= 10;
        num_digits++;
    }

    char digits[num_digits];
    int i = num_digits - 1;

    while (num != 0)
    {
        digits[i] = num % 10 + '0';
        num /= 10;
        i--;
    }

    for (int j = 0; j < num_digits; j++)
    {
        _putchar(digits[j]);
        printed_chars++;
    }

    return printed_chars;
}

int _print_unsigned_long_long(va_list args)
{
    unsigned long long num = va_arg(args, unsigned long long);
    int printed_chars = 0;

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_digits = 0;
    unsigned long long temp = num;
    while (temp != 0)
    {
        temp /= 10;
        num_digits++;
    }

    char digits[num_digits];
    int i = num_digits - 1;

    while (num != 0)
    {
        digits[i] = num % 10 + '0';
        num /= 10;
        i--;
    }

    for (int j = 0; j < num_digits; j++)
    {
        _putchar(digits[j]);
        printed_chars++;
    }

    return printed_chars;
}

int _print_octal_long_long(va_list args)
{
    unsigned long long num = va_arg(args, unsigned long long);
    int printed_chars = 0;

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_digits = 0;
    unsigned long long temp = num;
    while (temp != 0)
    {
        temp /= 8;
        num_digits++;
    }

    char digits[num_digits];
    int i = num_digits - 1;

    while (num != 0)
    {
        digits[i] = num % 8 + '0';
        num /= 8;
        i--;
    }

    for (int j = 0; j < num_digits; j++)
    {
        _putchar(digits[j]);
        printed_chars++;
    }

    return printed_chars;
}

int _print_hex_lower_long_long(va_list args)
{
    unsigned long long num = va_arg(args, unsigned long long);
    int printed_chars = 0;

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_digits = 0;
    unsigned long long temp = num;
    while (temp != 0)
    {
        temp /= 16;
        num_digits++;
    }

    char digits[num_digits];
    int i = num_digits - 1;

    while (num != 0)
    {
        int remainder = num % 16;
        if (remainder < 10)
            digits[i] = remainder + '0';
        else
            digits[i] = remainder - 10 + 'a';
        num /= 16;
        i--;
    }

    for (int j = 0; j < num_digits; j++)
    {
        _putchar(digits[j]);
        printed_chars++;
    }

    return printed_chars;
}

int _print_hex_upper_long_long(va_list args)
{
    unsigned long long num = va_arg(args, unsigned long long);
    int printed_chars = 0;

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
        return printed_chars;
    }

    int num_digits = 0;
    unsigned long long temp = num;
    while (temp != 0)
    {
        temp /= 16;
        num_digits++;
    }

    char digits[num_digits];
    int i = num_digits - 1;

    while (num != 0)
    {
        int remainder = num % 16;
        if (remainder < 10)
            digits[i] = remainder + '0';
        else
            digits[i] = remainder - 10 + 'A';
        num /= 16;
        i--;
    }

    for (int j = 0; j < num_digits; j++)
    {
        _putchar(digits[j]);
        printed_chars++;
    }

    return printed_chars;
}
