#ifndef FT_ERROR_H
# define FT_ERROR_H

typedef enum e_ftE
{
	ftE_ok = 0,
	ftE_fail,
	ftE_bad_alloc,
	ftE_bad_arg,
	ftE_parse_error,
	ftE_overflow,
	ftE_user_define_error_namespace = (1 << 15)
}			t_ftE;

t_ftE	ftE_perror(char const *msg, t_ftE err);

#endif
