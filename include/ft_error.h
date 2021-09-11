#ifndef FT_ERROR_H
# define FT_ERROR_H

typedef int t_error;

enum e_error
{
	error_no_error = 0,
	error_allocation_fail,
	error_parse_error,
	error_user_define_error = (1 << 31)
};

#endif
