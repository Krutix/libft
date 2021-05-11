#include "ft_string.h"
#include "stdlib.h"

void	ft_strarr_clear(char **s)
{
	size_t i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

size_t	ft_strarr_size(char **s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
