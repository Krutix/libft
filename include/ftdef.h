/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftdef.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:40:51 by krutix            #+#    #+#             */
/*   Updated: 2021/04/30 08:45:44 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTDEF_H
# define FTDEF_H

# include <stddef.h>
# include <limits.h>
# include <stdint.h>

/*
************************************************
**
**				boolean type
**
**	to transform non zero value to t_true
**			apply !!(x)
**
************************************************
*/

typedef enum e_bool
{
	t_false = 0,
	t_true = 1
}				t_bool;

/*
************************************************
**
**	short representation of common types
**
************************************************
*/
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
