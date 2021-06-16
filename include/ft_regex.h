#ifndef FT_REGEX_H
# define FT_REGEX_H

# include "ft_string.h"
# include "ft_vector.h"

typedef struct s_regex
{
    t_vector    __states;
}       t_regex;

t_regex     ft_regex_compile(char const *regex);
void        ft_regex_destroy(t_regex *compiled_regex);

#endif
