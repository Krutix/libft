/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:50:23 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/07 22:30:32 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcat_s(char *dest, const char *src, size_t size)
{
	if (dest == NULL || src == NULL)
		return (ft_strnlen_s(dest, size));
	return (ft_strlcat(dest, src, size));
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		n;

	n = ft_strnlen(dest, size);
	return (n + ft_strlcpy(dest + n, src, size - n));
}
