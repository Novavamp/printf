#include "main.h"

int main(void)
{
    int len;

    len = _printf("Let's try out our custom printf function!\n");
    _printf("Number of characters printed: %d\n", len);

    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, World!");
    _printf("Decimal: %d\n", 12345);
    _printf("Unsigned Decimal: %u\n", 98765);
    _printf("Octal: %o\n", 123);
    _printf("Lowercase Hexadecimal: %x\n", 456);
    _printf("Uppercase Hexadecimal: %X\n", 789);
    _printf("Floating-point: %f\n", 3.14159);
    _printf("Scientific Notation: %e\n", 0.000123);
    _printf("Pointer: %p\n", (void *)0x12345678);
    _printf("Long Decimal: %ld\n", 9876543210L);
    _printf("Long Unsigned Decimal: %lu\n", 9876543210UL);
    _printf("Long Octal: %lo\n", 1234567890L);
    _printf("Long Lowercase Hexadecimal: %lx\n", 1234567890L);
    _printf("Long Uppercase Hexadecimal: %lX\n", 1234567890L);
    _printf("Long Long Decimal: %lld\n", 123456789012345LL);
    _printf("Long Long Unsigned Decimal: %llu\n", 123456789012345ULL);
    _printf("Long Long Octal: %llo\n", 123456789012345ULL);
    _printf("Long Long Lowercase Hexadecimal: %llx\n", 123456789012345ULL);
    _printf("Long Long Uppercase Hexadecimal: %llX\n", 123456789012345ULL);
    _printf("Long Double: %Lf\n", 3.141592653589793238462643383279502884L);

    return 0;
}
