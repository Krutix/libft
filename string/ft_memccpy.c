/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:23:22 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:38:17 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n-- != 0)
		if ((*((unsigned char*)dest++) = *((unsigned char*)src++))
						== (unsigned char)c)
			return (dest);
	return (NULL);
}
