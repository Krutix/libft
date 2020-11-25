/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftdef.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:40:51 by krutix            #+#    #+#             */
/*   Updated: 2020/11/25 19:22:27 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTDEF_H
# define FTDEF_H

#include <stddef.h>
#include <limits.h>
#include <stdint.h>

typedef enum e_bool { t_false = 0, t_true = 1 } t_bool;

typedef unsigned int			uint;
typedef long int				lint;
typedef unsigned long int		ulint;
typedef long long int			llint;
typedef unsigned long long int	ullint;
typedef short int				sint;
typedef unsigned short int		usint;
typedef unsigned char			uchar;

/*
**	general data type for data structure
*/
typedef union	u_data {
	void		*p;
	char		*s;
	intptr_t	i;
	uintptr_t	u;
}				t_data;


#endif