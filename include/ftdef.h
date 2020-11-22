/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftdef.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:40:51 by krutix            #+#    #+#             */
/*   Updated: 2020/11/22 22:29:02 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTDEF_H
# define FTDEF_H

#include <stddef.h>
#include <limits.h>

typedef enum e_bool { t_false = 0, t_true = 1 } t_bool;

typedef unsigned int			uint;
typedef long int				lint;
typedef unsigned long int		ulint;
typedef long long int			llint;
typedef unsigned long long int	ullint;
typedef short int				sint;
typedef unsigned short int		usint;
typedef unsigned char			uchar;

typedef union	u_data {
	void		*p;
	llint		i;
}				t_data;


#endif