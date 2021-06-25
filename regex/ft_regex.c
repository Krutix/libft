#include "__ft_regex.h"
#include "stdlib.h"

static char *basic_charsets[] = {
	"",
	"\t\r\v\f\n ",
	"0123456789",
	"01234567",
	"0123456789abcdefABCDEF",
	NULL
};

void	set_basic_charset(t_regex *re)
{
	for (char **s_ptr = basic_charsets; *s_ptr; s_ptr++)
	{
		char *s = ft_strdup(*s_ptr);
		ft_vec_push_back(&re->__charsets, &s);
	}
}

void	ft_regex_compile(t_regex *re, char const *re_str)
{
	t_re_post	*re_post;

	ft_vec_construct(&re->__states, sizeof(t_regex_state));
	ft_vec_construct(&re->__charsets, sizeof(char *));
	set_basic_charset(re);
	re_post = ft_re2post(re_str);
	ft_post2nfa(re, re_post);
}

void	free_charset(char **s)
{
	free(*s);
}

void	ft_regex_destroy(t_regex *re)
{
	ft_vec_destructor(&re->__charsets, (void(*)(void*))&free_charset);
	ft_vec_destructor(&re->__states, NULL);
}
