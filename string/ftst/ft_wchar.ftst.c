#include "ft_string.h"
#include "ftst.h"

TEST(ft_wchtoch)
{
    char buffer[1024];
    EQ(ft_wchtoch(0x000000b5, &buffer[0]), 2);
    EQ(buffer[0], 0b11000010, c);
    EQ(buffer[1], 0b10110101, c);
    EQ(ft_wchtoch(0x000008a2, &buffer[0]), 3);
    EQ(buffer[0], 0b11100000, c);
    EQ(buffer[1], 0b10100010, c);
    EQ(buffer[2], 0b10100010, c);
}

TEST(ft_wstrtostr)
{
    wchar_t *str = L"鳩😎";
    char buffer[10];
    size_t len;
    EQ(len = ft_wstrtostr(str, buffer), 7);
    buffer[len] = '\0';
    char cmp_str[10] = {(char)0b11101001, (char)0b10110011, (char)0b10101001, (char)0b11110000, (char)0b10011111, (char)0b10011000, (char)0b10001110, (char)0};
    STR_EQ(buffer, cmp_str);
}
