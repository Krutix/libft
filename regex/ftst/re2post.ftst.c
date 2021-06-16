#include "ftst.h"
#include "../__ft_regex.h"

void pr(t_re_post *p)
{
    for (;*p;p++)
        fprintf(stderr, "%c'", (char)(*p & 255));
    fprintf(stderr, "\n");
}

TEST(ft_re2post)
{
    pr(ft_re2post("a"));
    pr(ft_re2post("ac"));
    pr(ft_re2post("aac"));
    pr(ft_re2post("aaac"));
    pr(ft_re2post("aa|vb"));
    pr(ft_re2post("aaa|vdb"));
    pr(ft_re2post("aaas|vdba"));
    pr(ft_re2post("aa+as|v?dba"));
    pr(ft_re2post("a(aa)+"));
    pr(ft_re2post("a(a(b|b)?)+"));
    pr(ft_re2post("a(a(bb)?)+"));
}
