#include "ft_string.h"

int  ft_wstrtostr(wchar_t *str, char *buffer)
{
    char *const buffer_start = buffer;
    int         pr;

    while (*str)
    {
        if (!(pr = ft_wchtoch(*str, buffer)))
            return (-1);
        buffer += pr;
        str++;
    }
    *buffer = '0';
    return (buffer - buffer_start);
}

int  ft_wchtoch(wchar_t ch, char *buffer)
{
    if (ch <= 0x7f) {
        buffer[0] = ch;
        return 1;
    }
    if (ch <= 0x7ff) {
        buffer[0] = 0xC0 | (ch >> 6);
        buffer[1] = 0x80 | (ch & 0x3F);
        return 2;
    }
    if (ch <= 0xFFFF) {
        buffer[0] = 0xE0 | (ch >> 12);
        buffer[1] = 0x80 | ((ch >> 6) & 0x3F);
        buffer[2] = 0x80 | (ch & 0x3F);
        return 3;
    }
    if (ch <= 0x10FFFF) {
        buffer[0] = 0xF0 | (ch >> 18);
        buffer[1] = 0x80 | ((ch >> 12) & 0x3F);
        buffer[2] = 0x80 | ((ch >> 6) & 0x3F);
        buffer[3] = 0x80 | (ch & 0x3F);
        return 4;
    }
    return 0;
}
