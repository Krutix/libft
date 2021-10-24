#ifndef FT_REGEX_H
# define FT_REGEX_H

# include "ft_string.h"
# include "ft_vector.h"

typedef struct s_regex
{
    t_vector    __states;
}       t_regex;

t_ft_err    ft_regex_compile(t_regex *re, char const *regex);
t_ft_err    ft_regex_match(t_regex *compiled_regex, char const *str);
void        ft_regex_destroy(t_regex *compiled_regex);

#endif
