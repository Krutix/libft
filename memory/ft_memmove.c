/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:12:38 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:19:07 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "memory.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	if (dest < src)
		while (n-- != 0)
			*(d++) = *(s++);
	else
		while (n-- != 0)
			*(d + n) = *(s + n);
	return (dest);
}
