/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:58:07 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/23 04:18:19 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "ft_string.h"

inline static const char
			*ft_strchr_longword(const char *start, unsigned char c)
{
	const __uint64_t *longword_ptr;
	const __uint64_t himagic = 0x8080808080808080LL;
	const __uint64_t lomagic = 0x0101010101010101LL;
	__uint64_t repeat_c;
	__uint64_t longword;

	repeat_c = c << 8 | c;
	repeat_c |= repeat_c << 16;
	repeat_c |= repeat_c << 32;
	longword_ptr = (__uint64_t*) start;
	while (1)
	{
		longword = *longword_ptr;
		if (((longword - lomagic) & ~longword & himagic) != 0 ||
			(((longword ^ repeat_c) - lomagic) & ~longword & himagic) != 0)
			break ;
		longword_ptr++;
	}
	start = ((char*)(longword_ptr));
	while (*start && *start != c)
		start++;
	if (*start == c)
		return (start);
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	const char *char_ptr;

	char_ptr = s;
	while (*char_ptr && (((__uint64_t)char_ptr & (sizeof(__uint64_t) - 1)) != 0))
		if (*char_ptr++ == (unsigned char)c)
			return ((void*)--char_ptr);
	return ((void*)ft_strchr_longword(char_ptr, c));
}
