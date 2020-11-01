/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:20:04 by fdiego            #+#    #+#             */
/*   Updated: 2020/10/31 23:44:26 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;

	if (!dest && !src)
		return (NULL);
	d = dest;
	while (n-- != 0)
		*(char*)(d++) = *(char*)(src++);
	return (dest);
}
