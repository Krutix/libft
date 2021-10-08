#ifndef FT_ERROR_H
# define FT_ERROR_H

typedef enum e_ft_err
{
	ft_err_ok = 0,
	ft_err_fail,
	ft_err_bad_alloc,
	ft_err_bad_arg,
	ft_err_parse_error,
	ft_err_overflow,
	ft_err_user_define_error_namespace = (1 << 15)
}			t_ft_err;

t_ft_err	ft_err_perror(char const *msg, t_ft_err err);

#endif
