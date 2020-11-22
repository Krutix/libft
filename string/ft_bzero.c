/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:16:25 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:38:02 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
**	size_t big_word;
**
**	big_word = size / sizeof(long);
**	size %= sizeof(long);
**	while (big_word != 0)
**	{
**		*(long*)(mem) ^= *(long*)(mem);
**		mem += sizeof(long);
**		big_word--;
**	}
*/

void	ft_bzero(void *mem, size_t size)
{
	while (size-- != 0)
	{
		*(char*)(mem) ^= *(char*)(mem);
		mem++;
	}
}
