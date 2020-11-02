/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount_if.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:27:15 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 16:27:20 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdef.h"

size_t	ft_strcount_if(const char *str, t_bool (*counter)(char *))
{
	size_t c;

	c = 0;
	while (*str)
		if (counter(str++))
			c++;
	return (c);
}
