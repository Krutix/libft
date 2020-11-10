/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount_if.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:27:15 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:25:39 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strcount_if(const char *str, t_bool (*counter)(const char *))
{
	size_t c;

	c = 0;
	while (*str)
		if (counter(str++))
			c++;
	return (c);
}
