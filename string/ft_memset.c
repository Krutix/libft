/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:17:21 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 18:02:30 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

/*
**	__uint32_t	vvvv;
**	size_t		big_word;
** 
**	vvvv = (unsigned char)value;
**	vvvv = (vvvv << 8) | vvvv;
**	vvvv = (vvvv << 16) | vvvv;
**	big_word = size / (sizeof(__uint32_t));
**	size %= (sizeof(__uint32_t));
**	while (big_word-- != 0)
**	{
**		*(__uint32_t*)(mem) = vvvv;
**		mem += sizeof(__uint32_t);
**	}
*/

void	*ft_memset(void *mem, int value, size_t size)
{
	const void	*m = mem;
	while (size-- != 0)
		*(unsigned char*)(mem++) = (unsigned char)value;
	return ((void*)m);
}
