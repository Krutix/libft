#include "ftst.h"
#include "ft_regex.h"

TEST(ft_regex)
{
	t_regex re;
	ft_regex_compile(&re, "abc");
	IS_TRUE(ft_regex_match(&re, "abc"));
	IS_FALSE(ft_regex_match(&re, "aaa"));
	IS_FALSE(ft_regex_match(&re, "abcc"));
	IS_FALSE(ft_regex_match(&re, "ab"));
}
 