#include "ft_string.h"

#define FTST_SUB_TEST
#include "ftst.h"

TEST(ft_memccpy_basic_test)
{
    char buffer[126];
    ft_memccpy(buffer, "bbbbbbbbbba\0bbbbbbbbbbbbbbbbbbbbbbbb", '\0', 22);
    IS_TRUE(memcmp(buffer, "bbbbbbbbbba", 12) == 0);

    buffer[0] = '\0';
    for (int i = 'A'; i <= 'z'; i++)
    {
        char minibuf[2];
        minibuf[0] = i;
        minibuf[1] = '\0';
        strcat(buffer, minibuf);
    }
    char sec_buffer[126] = "-------------------------------------------------------------------------";
    for (int i = 'A'; i <= 'z'; i++)
    {
        char *ptr;
        EQ(*(char*)((ptr = ft_memccpy(sec_buffer, buffer, i, 58)) - 1), i, c);
        EQ(*ptr, '-', c);
        IS_TRUE(memcmp(sec_buffer, buffer, i - 65) == 0);
    }
}
