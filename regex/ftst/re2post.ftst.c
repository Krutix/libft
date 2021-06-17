#include "ftst.h"
#include "../__ft_regex.h"

char *post2str(t_re_post *p)
{
    static char buffer[1024] = "";
    size_t i;
    for (i = 0; *p; i++, p++)
        buffer[i] = (char)(*p & 255);
    buffer[i] = 0;
    return buffer;
}

TEST(ft_re2post)
{
    STR_EQ(post2str(ft_re2post("a")), "a");
    STR_EQ(post2str(ft_re2post("ac")), "ac^");
    STR_EQ(post2str(ft_re2post("abc")), "ab^c^");
    STR_EQ(post2str(ft_re2post("ab|cd")), "ab^cd^|");
    STR_EQ(post2str(ft_re2post("abv?|c+d")), "ab^v?^c+d^|");
    STR_EQ(post2str(ft_re2post("a(bv)?|c+d")), "abv^?^c+d^|");
    STR_EQ(post2str(ft_re2post("a(sd(b|v))?")), "asd^bv|^?^");
}
