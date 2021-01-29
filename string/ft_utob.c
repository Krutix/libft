#include "ft_string.h"

size_t  ft_utob(char *buffer, t_ullint num)
{
    const size_t size_len = ft_ulen(num);

    buffer += size_len;
    *buffer-- = '\0';
    while (num >= 10)
    {
        *buffer-- = num % 10 + '0';
        num /= 10;
    }
    *buffer = num % 10 + '0';
    return (size_len);
}