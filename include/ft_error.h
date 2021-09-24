#ifndef FT_ERROR_H
# define FT_ERROR_H

typedef int t_ftE;

enum e_error
{
	ftE_ok = 0,
	ftE_fail,
	ftE_bad_alloc,
	ftE_bad_arg,
	ftE_parse_error,
	ftE_user_define_error_namespace = (1 << 15)
};

#endif
