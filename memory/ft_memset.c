/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:17:21 by fdiego            #+#    #+#             */
/*   Updated: 2020/10/31 22:16:16 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *mem, int value, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
		*(char*)(mem + i++) = (char)value;
	return (mem);
}
