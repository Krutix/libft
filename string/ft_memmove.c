/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:12:38 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:37:01 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdio.h>

static void	*ft_memcpy_back(void *dest, const void *src, size_t n)
{
	char	*d;
	size_t	big_word;

	d = dest + n;
	src += n;
	big_word = n / sizeof(__uint64_t);
	n %= sizeof(__uint64_t);
	while (big_word-- != 0)
	{
		d -= sizeof(__uint64_t);
		src -= sizeof(__uint64_t);
		*(__uint64_t*)(d) = *(__uint64_t*)(src);
	}
	while (n-- != 0)
		*--d = *(char*)(--src);
	return (dest);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest <= src)
		ft_memcpy(dest, src, n);
	else
		ft_memcpy_back(dest, src, n);
	return (dest);
}
