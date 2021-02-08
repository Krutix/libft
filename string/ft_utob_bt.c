#include "ft_string.h"

char    *ft_utob_bt(char *buffer_end, t_ullint num)
{
    while (num >= 10)
    {
        *buffer_end-- = "0123456789"[num % 10];
        num /= 10;
    }
    *buffer_end = "0123456789"[num % 10];
    return (buffer_end);
}

char    *ft_utob_bt_16(char *buffer_end, t_ullint num, char *base)
{
    while (num >= 16)
    {
        *buffer_end-- = base[num % 16];
        num /= 16;
    }
    *buffer_end = base[num % 16];
    return (buffer_end);
}

char    *ft_utob_bt_2(char *buffer_end, t_ullint num)
{
    while (num >= 2)
    {
        *buffer_end-- = "01"[num % 2];
        num /= 2;
    }
    *buffer_end = "01"[num % 2];
    return (buffer_end);
}

char    *ft_utob_bt_n(char *buffer_end, t_ullint num, char *base)
{
    const size_t base_len = ft_strlen(base);

    while (num >= base_len)
    {
        *buffer_end-- = base[num % base_len];
        num /= base_len;
    }
    *buffer_end = base[num % base_len];
    return (buffer_end);
}
