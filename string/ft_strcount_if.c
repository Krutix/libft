/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount_if.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:27:15 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 18:21:46 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_string.h"

size_t	ft_strcount_if(const char *str, t_bool (*counter)(const char *))
{
	size_t c;

	c = 0;
	while (*str)
		if (counter(str++))
			c++;
	return (c);
}
