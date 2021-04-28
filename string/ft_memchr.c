/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:40:46 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 10:22:55 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdef.h"

inline static const t_uchar	*ft_memchr_longword(const t_uchar *start, \
									t_uchar c, const t_uchar *const end_ptr)
{
	const __uint64_t	*longword_ptr;
	const __uint64_t	himagic = 0x8080808080808080LL;
	const __uint64_t	lomagic = 0x0101010101010101LL;
	__uint64_t			repeat_c;
	__uint64_t			longword;

	repeat_c = c << 8 | c;
	repeat_c |= repeat_c << 16;
	repeat_c |= repeat_c << 32;
	longword_ptr = (__uint64_t *)start;
	while ((unsigned long)(end_ptr - \
			(t_uchar *)longword_ptr) >= sizeof(__uint64_t))
	{
		longword = repeat_c ^ *longword_ptr;
		if (((longword - lomagic) & ~longword & himagic) != 0)
			break ;
		longword_ptr++;
	}
	start = (t_uchar *)(longword_ptr);
	while (start != end_ptr)
		if (*start++ == c)
			return (--start);
	return (NULL);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	const t_uchar			*char_ptr;
	const t_uchar *const	end_ptr = s + n;

	char_ptr = s;
	while (char_ptr < end_ptr && (((long long)char_ptr & \
				(sizeof(__uint64_t) - 1)) != 0))
		if (*char_ptr++ == (t_uchar)c)
			return ((void *)--char_ptr);
	return ((void *)ft_memchr_longword(char_ptr, c, end_ptr));
}
