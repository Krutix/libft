/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:23:22 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 01:13:27 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	if (!dest && !src)
		return (NULL);
	while (n-- != 0)
		if ((*((unsigned char*)dest++) = *((unsigned char*)src++))
						== (unsigned char)c)
			return (dest);
	return (NULL);
}
