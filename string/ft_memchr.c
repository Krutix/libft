/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:40:46 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:37:31 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_string.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- != 0)
		if (*(char*)(s++) == (char)c)
			return ((void*)s - 1);
	return (NULL);
}
