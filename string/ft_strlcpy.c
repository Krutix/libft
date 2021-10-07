/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:49:33 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/07 22:34:49 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_string.h"

size_t	ft_strlcpy_s(char *dest, const char *src, size_t size)
{
	if (dest == NULL || src == NULL)
		return (ft_strlen_s(src));
	return (ft_strlcpy(dest, src, size));
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const size_t	len = ft_strlen(src);
	size_t			n;

	if (len < (size - 1))
		n = len;
	else
		n = size - 1;
	if (size != 0)
	{
		ft_memcpy(dest, src, n);
		dest[n] = '\0';
	}
	return (len);
}
