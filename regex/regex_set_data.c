#include "__ft_regex.h"

void	regex_set_data(t_regex *re, void *data)
{
	size_t			i;
	t_regex_state	*st;

	i = 0;
	while (i < re->__states.size)
	{
		st = ft_vec_at(&re->__states, i);
		st->data = data;
	}
}

t_ft_err	regex_concat_or(t_regex *left, t_regex *right)
{
	return (ft_err_ok);
}
