#include "__ft_regex.h"
#include "stdlib.h"

t_ft_err	ft_regex_compile(t_regex *re, char const *re_str)
{
	t_re_post	*re_post;

	ft_vec_construct(&re->__states, sizeof(t_regex_state));
	re_post = ft_re2post(re_str);
	ft_post2nfa(re, re_post);
	return (ft_err_ok);
}

void	ft_regex_destroy(t_regex *re)
{
	ft_vec_destructor(&re->__states, NULL);
}
