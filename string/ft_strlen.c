/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:48:11 by fdiego            #+#    #+#             */
/*   Updated: 2020/12/31 23:31:52 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"
#include "stdio.h"

/*
** Bits 31, 24, 16, and 8 of this number are zero.  Call these bits
** the "holes."  Note that there is a hole just to the left of
** each byte, with an extra at the end:
**
** bits:  01111110 11111110 11111110 11111111
** bytes: AAAAAAAA BBBBBBBB CCCCCCCC DDDDDDDD
**
** The 1-bits make sure that carries propagate to the next 0-bit.
** The 0-bits provide holes for carries to fall into.
*/

inline static const char	*ft_strlen_check(const char *char_ptr)	
{
	if (char_ptr[0] == 0)
		return (char_ptr);
	if (char_ptr[1] == 0)
		return (char_ptr + 1);
	if (char_ptr[2] == 0)
		return (char_ptr + 2);
	if (char_ptr[3] == 0)
		return (char_ptr + 3);
	if (char_ptr[4] == 0)
		return (char_ptr + 4);
	if (char_ptr[5] == 0)
		return (char_ptr + 5);
	if (char_ptr[6] == 0)
		return (char_ptr + 6);
	if (char_ptr[7] == 0)
		return (char_ptr + 7);
	return (NULL);
}

inline static const char	*ft_strlen_longword(const char *start)
{
	const __uint64_t	*longword_ptr;
	const __uint64_t	himagic = 0x8080808080808080LL;
	const __uint64_t	lomagic = 0x0101010101010101LL;
	__uint64_t			longword;

	longword_ptr = (__uint64_t*)start;
	while (1)
	{
		longword = *longword_ptr++;
		if (((longword - lomagic) & ~longword & himagic) != 0)
			if ((start = ft_strlen_check((const char*)(longword_ptr - 1))))
				return (start);
	}
}

size_t						ft_strlen(const char *str)
{
	const char *char_ptr;

	char_ptr = str;
	while ((((__uint64_t)char_ptr & (sizeof(__uint64_t) - 1)) != 0))
		if (*char_ptr++ == '\0')
			return (--char_ptr - str);
	return (ft_strlen_longword(char_ptr) - str);
}
