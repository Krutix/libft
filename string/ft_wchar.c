#include "ft_string.h"

size_t  ft_wstrtostr(wchar_t *ch, char *buffer)
{
}

size_t  ft_wchtoch(wchar_t ch, char *buffer)
{
    if (ch <= 0x7F) {
        buffer[0] = ch;
        return 1;
    }
    if (ch <= 0x7FF) {
        buffer[0] = 0xC0 | (ch >> 6);            /* 110xxxxx */
        buffer[1] = 0x80 | (ch & 0x3F);          /* 10xxxxxx */
        return 2;
    }
    if (ch <= 0xFFFF) {
        buffer[0] = 0xE0 | (ch >> 12);           /* 1110xxxx */
        buffer[1] = 0x80 | ((ch >> 6) & 0x3F);   /* 10xxxxxx */
        buffer[2] = 0x80 | (ch & 0x3F);          /* 10xxxxxx */
        return 3;
    }
    if (ch <= 0x10FFFF) {
        buffer[0] = 0xF0 | (ch >> 18);           /* 11110xxx */
        buffer[1] = 0x80 | ((ch >> 12) & 0x3F);  /* 10xxxxxx */
        buffer[2] = 0x80 | ((ch >> 6) & 0x3F);   /* 10xxxxxx */
        buffer[3] = 0x80 | (ch & 0x3F);          /* 10xxxxxx */
        return 4;
    }
    return 0;
}
