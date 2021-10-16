/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftdef.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:11:36 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/08 23:13:43 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTDEF_H
# define FTDEF_H

# include <stddef.h>
# include <limits.h>
# include <stdint.h>
# include <ft_error.h>

# define PASS ((void)NULL)

typedef size_t (				*t_hash_func)(void *);
typedef int (					*t_cmp_func)(void *, void *);
typedef void (					*t_upd_func)(void *, void *);
typedef void (					*t_destr_func)(void *);
typedef void (					*t_process_func)(void *);
typedef void (					*t_construct)(void *, void *);

typedef enum e_bool
{
	ft_false = 0,
	ft_true = 1
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
