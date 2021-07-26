#ifndef FTDEF_H
# define FTDEF_H

# include <stddef.h>
# include <limits.h>
# include <stdint.h>

# define PASS ((void)NULL)

typedef enum e_bool
{
	t_false = 0,
	t_true = 1
}				t_bool;

typedef unsigned int			t_uint;
typedef long int				t_lint;
typedef unsigned long int		t_ulint;
typedef long long int			t_llint;
typedef unsigned long long int	t_ullint;
typedef short int				t_sint;
typedef unsigned short int		t_usint;
typedef unsigned char			t_uchar;
typedef long double				t_ldouble;

#endif
