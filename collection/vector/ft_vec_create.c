/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:12:10 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:10:24 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

void		ft_vec_constructor(t_vector **vec)
{
	*vec = malloc(sizeof(t_vector));
	if (!*vec)
		return ;
	(*vec)->size = 0;
	(*vec)->array = NULL;
	(*vec)->reserv = 4;
	ft_vec_realloc(*vec, (*vec)->reserv);
}
