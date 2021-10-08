#ifndef FT_ERROR_H
# define FT_ERROR_H

typedef enum e_ft_err
{
	ft_err_ok = 0,
	ft_err_fail,
	ft_err_bad_alloc,
	ft_err_bad_arg,
	ft_err_toomanyargs,
	ft_err_bad_syntax,
	ft_err_overflow,
	ft_err_underflow,
	ft_err_unclosedquotes,
	ft_err_bad_access,
	ft_err_bad_cmd,
	ft_err_isadir,
	ft_err_bad_substitution
}			t_ft_err;

t_ft_err	ft_err_perror(char const *msg, t_ft_err err);
char const	*ft_strerr(t_ft_err err);

#endif
