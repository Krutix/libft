#include "ftst.h"
#include "ft_regex.h"

TEST(re_simple_linear)
{
	t_regex re;
	ft_regex_compile(&re, "abc");
	IS_TRUE(ft_regex_match(&re, "abc"));
	IS_FALSE(ft_regex_match(&re, "aaa"));
	IS_FALSE(ft_regex_match(&re, "abcc"));
	IS_FALSE(ft_regex_match(&re, "ab"));
	ft_regex_destroy(&re);
}
 
TEST(re_simple_split)
{
	t_regex re;
	ft_regex_compile(&re, "a|bc");
	IS_TRUE(ft_regex_match(&re, "a"));
	IS_TRUE(ft_regex_match(&re, "bc"));
	IS_FALSE(ft_regex_match(&re, "abcc"));
	IS_FALSE(ft_regex_match(&re, "b"));
	IS_FALSE(ft_regex_match(&re, "ab"));
	IS_FALSE(ft_regex_match(&re, "abc"));
	IS_FALSE(ft_regex_match(&re, "bca"));
	ft_regex_destroy(&re);
}
 
TEST(re_simple_split_2)
{
	t_regex re;
	ft_regex_compile(&re, "a|b|c|d");
	IS_TRUE(ft_regex_match(&re, "a"));
	IS_TRUE(ft_regex_match(&re, "b"));
	IS_TRUE(ft_regex_match(&re, "c"));
	IS_TRUE(ft_regex_match(&re, "d"));
	IS_FALSE(ft_regex_match(&re, "abcc"));
	IS_FALSE(ft_regex_match(&re, "g"));
	IS_FALSE(ft_regex_match(&re, "ab"));
	IS_FALSE(ft_regex_match(&re, "ab"));
	IS_FALSE(ft_regex_match(&re, "abc"));
	IS_FALSE(ft_regex_match(&re, "bca"));
	ft_regex_destroy(&re);
}
 
TEST(re_simple_multy)
{
	t_regex re;
	ft_regex_compile(&re, "a*");
	IS_TRUE(ft_regex_match(&re, ""));
	IS_TRUE(ft_regex_match(&re, "aa"));
	IS_TRUE(ft_regex_match(&re, "aaa"));
	IS_TRUE(ft_regex_match(&re, "aaaaa"));
	IS_FALSE(ft_regex_match(&re, "aaab"));
	IS_FALSE(ft_regex_match(&re, "b"));
	ft_regex_destroy(&re);
}
 
TEST(re_simple_multy_with_concat)
{
	t_regex re;
	ft_regex_compile(&re, "ba*");
	IS_TRUE(ft_regex_match(&re, "b"));
	IS_TRUE(ft_regex_match(&re, "ba"));
	IS_TRUE(ft_regex_match(&re, "baa"));
	IS_TRUE(ft_regex_match(&re, "baaaa"));
	IS_FALSE(ft_regex_match(&re, "aaab"));
	IS_FALSE(ft_regex_match(&re, "baaab"));
	ft_regex_destroy(&re);
}
 
TEST(re_simple_multy_with_concat_2)
{
	t_regex re;
	ft_regex_compile(&re, "(ba)*");
	IS_TRUE(ft_regex_match(&re, ""));
	IS_TRUE(ft_regex_match(&re, "ba"));
	IS_TRUE(ft_regex_match(&re, "baba"));
	IS_TRUE(ft_regex_match(&re, "bababa"));
	IS_FALSE(ft_regex_match(&re, "bab"));
	IS_FALSE(ft_regex_match(&re, "babaa"));
	ft_regex_destroy(&re);
}

TEST(re_simple_one_multy)
{
	t_regex re;
	ft_regex_compile(&re, "ba+");
	IS_FALSE(ft_regex_match(&re, "b"));
	IS_TRUE(ft_regex_match(&re, "ba"));
	IS_TRUE(ft_regex_match(&re, "baa"));
	IS_TRUE(ft_regex_match(&re, "baaaa"));
	IS_FALSE(ft_regex_match(&re, "aaab"));
	IS_FALSE(ft_regex_match(&re, "baaab"));
	ft_regex_destroy(&re);
}

TEST(re_simple_one_zero)
{
	t_regex re;
	ft_regex_compile(&re, "ba?");
	IS_TRUE(ft_regex_match(&re, "b"));
	IS_TRUE(ft_regex_match(&re, "ba"));
	IS_FALSE(ft_regex_match(&re, "baa"));
	IS_FALSE(ft_regex_match(&re, "aa"));
	ft_regex_destroy(&re);
}

TEST(re_slesh)
{
	t_regex re;
	ft_regex_compile(&re, "\\+\\*\\?\\|");
	IS_TRUE(ft_regex_match(&re, "+*?|"));
	ft_regex_destroy(&re);
}