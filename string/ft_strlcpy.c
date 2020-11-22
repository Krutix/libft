/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:49:33 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:38:45 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_string.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const size_t	len = ft_strlen(src);
	const size_t	n = len < (size - 1) ? len : (size - 1);

	if (size != 0)
	{
		ft_memcpy(dest, src, n);
		dest[n] = '\0';
	}
	return (len);
}
