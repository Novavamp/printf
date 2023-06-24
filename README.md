```markdown
# printf Function

The `_printf` function is a custom implementation of the C `printf` function that takes a format string and a variable number of arguments, and prints the formatted output to the console.

## Usage

To use the `_printf` function, include the `main.h` header file in your C program:

```c
#include "main.h"
```

Then, call the `_printf` function with the desired format string and arguments:

```c
int num = 42;
char str[] = "world";
_printf("Hello, %s! The answer is %d.\n", str, num);
```

This will print the following to the console:

```
Hello, world! The answer is 42.
```

Note that the format string contains two format specifiers: `%s` and `%d`. The first `%s` specifier is replaced with the string "world", and the second `%d` specifier is replaced with the integer value 42. The newline character `\n` at the end of the format string is printed as-is.

## Supported Format Specifiers

This `_printf` implementation supports the following format specifiers:

- `%c` for characters
- `%s` for strings
- `%d` and `%i` for signed decimal integers
- `%u` for unsigned decimal integers
- `%x` and `%X` for hexadecimal integers (lowercase and uppercase, respectively)
- `%o` for octal integers
- `%p` for pointers
- `%%` for a literal '%' character

## Return Value

The `_printf` function returns the number of characters printed to the console or a negative value if an error occurred.

## Contributing

If you would like to contribute to this project, please open a pull request with your changes. All contributions are welcome!
```
Note: The above text is written in Markdown format, suitable for documentation purposes, such as in a README file for the ALX Holberton School project.
