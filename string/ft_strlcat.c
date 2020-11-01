/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:50:23 by fdiego            #+#    #+#             */
/*   Updated: 2020/10/31 23:39:03 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		d_len;

	d = dest;
	s = src;
	n = size;
	while (n != 0 && *d)
	{
		d++;
		n--;
	}
	d_len = d - dest;
	if (n == 0)
		return (d_len + ft_strlen(src));
	while (*s)
	{
		if (n != 1 && n--)
			*d++ = *s;
		s++;
	}
	*d = '\0';
	return (d_len + (s - src));
}
