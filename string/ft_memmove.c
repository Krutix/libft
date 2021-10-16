/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:12:38 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/07 22:03:27 by fdiego           ###   ########.fr       */
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
		*(__uint64_t *)(d) = *(__uint64_t *)(src);
	}
	while (n-- != 0)
		*--d = *(char *)(--src);
	return (dest);
}

void	*ft_memmove_s(void *dest, const void *src, size_t n)
{
	if (dest == NULL || src == NULL)
		return (NULL);
	return (ft_memmove(dest, src, n));
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest <= src)
		ft_memcpy(dest, src, n);
	else
		ft_memcpy_back(dest, src, n);
	return (dest);
}
