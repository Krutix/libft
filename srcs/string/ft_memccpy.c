/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:23:22 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/07 21:56:09 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdint.h>

void	*ft_memccpy_s(void *dest, const void *src, int c, size_t n)
{
	if (dest == NULL || src == NULL)
		return (NULL);
	return (ft_memccpy(dest, src, c, n));
}

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	uint64_t	repeat_c;
	uint64_t	longword;

	repeat_c = (t_uchar)c << 8 | (t_uchar)c;
	repeat_c |= repeat_c << 16;
	repeat_c |= repeat_c << 32;
	while (n >= sizeof(uint64_t))
	{
		longword = *(uint64_t *)src;
		longword ^= repeat_c;
		if (((longword - 0x0101010101010101LL) & \
				~longword & 0x8080808080808080LL) != 0)
			break ;
		*(uint64_t *)dest = *(uint64_t *)src;
		dest += sizeof(uint64_t);
		src += sizeof(uint64_t);
		n -= sizeof(uint64_t);
	}
	while (n-- != 0)
	{
		*((t_uchar *)dest++) = *((t_uchar *)src++);
		if (*(t_uchar *)(dest - 1) == (t_uchar)c)
			return (dest);
	}
	return (NULL);
}
