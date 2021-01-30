#include "ft_string.h"

#include "ftst.h"

TEST(ft_strchr_base_test)
{
    char* find_uniq = "0123456789abcdefghtryuilo";
    for (size_t i = 0; i < 25; i++)
        EQ(ft_strchr(find_uniq, find_uniq[i]) - find_uniq, i);
    EQ(ft_strchr(find_uniq, ':'), NULL, s)
    find_uniq = "002345678900cdefgh11yuilo";
    EQ(ft_strchr(find_uniq, '0'), &find_uniq[0], s)
    EQ(ft_strchr(find_uniq, '1'), &find_uniq[18], s)
    find_uniq = "00234567890\0defgh11yuilo";
    EQ(ft_strchr(find_uniq, 'd'), NULL, s)
    find_uniq = "00234567890\0defgh11yuilo";
    EQ(ft_strchr(find_uniq, '\0'), &find_uniq[11], s)
}
