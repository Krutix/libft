/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:17:21 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:19:11 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "memory.h"

void	*ft_memset(void *mem, int value, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
		*(char*)(mem + i++) = (char)value;
	return (mem);
}
