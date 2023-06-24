#include <stdio.h>
#include <unistd.h>

int _getchar()
{
    char c;
    if (read(0, &c, 1) == 1)
        return c;
    return EOF;
}
