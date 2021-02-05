#include "ft_string.h"

size_t  ft_utob(char *buffer, t_ullint num)
{
    const size_t size_len = ft_ulen(num);

    buffer += size_len;
    *buffer-- = '\0';
    ft_utob_bt(buffer, num);
    return (size_len);
}

size_t  ft_utob_16(char *buffer, t_ullint num, char *base)
{
    const size_t size_len = ft_ulen_16(num);

    buffer += size_len;
    *buffer-- = '\0';
    ft_utob_bt_16(buffer, num, base);
    return (size_len);
}

size_t  ft_utob_2(char *buffer, t_ullint num)
{
    const size_t size_len = ft_ulen_2(num);

    buffer += size_len;
    *buffer-- = '\0';
    ft_utob_bt_2(buffer, num);
    return (size_len);
}

size_t  ft_utob_n(char *buffer, t_ullint num, char *base)
{
    const size_t base_len = ft_strlen(base);
    const size_t size_len = ft_ulen_n(num, base_len);

    buffer += size_len;
    *buffer-- = '\0';
    while (num >= base_len)
    {
        *buffer-- = base[num % base_len];
        num /= base_len;
    }
    *buffer = base[num % base_len];
    return (size_len);
}
