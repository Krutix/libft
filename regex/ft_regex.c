#include "__ft_regex.h"

void	ft_regex_compile(t_regex *re, char const *re_str)
{
	t_re_post	*re_post;

	re_post = ft_re2post(re_str);
	ft_post2nfa(re, re_post);
}