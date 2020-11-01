/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:49:33 by fdiego            #+#    #+#             */
/*   Updated: 2020/10/31 22:49:34 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;

	d = dest;
	s = src;
	n = size;
	if (n != 0)
		while (--n != 0)
			if ((*(d++) = *(s++)) == '\0')
				break ;
	if (n == 0)
	{
		if (size != 0)
			*d = '\0';
		while (*(s++))
			(void)s;
	}
	return (s - src - 1);
}
