/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftdef.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:11:36 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:11:37 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTDEF_H
# define FTDEF_H

# include <stddef.h>
# include <limits.h>
# include <stdint.h>
# include <ft_error.h>

# define PASS ((void)NULL)

typedef size_t (				*t_hashfunc)(void *);
typedef int (					*t_cmpfunc)(void *, void *);
typedef void (					*t_updfunc)(void *, void *);
typedef void (					*t_destrfunc)(void *);
typedef void (					*t_construct)(void *, void *);

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
