/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:56:59 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 09:12:14 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*l;

	l = NULL;
	while (*s)
	{
		if (*s == (char)c)
			l = (char *)s;
		s++;
	}
	if (l == NULL)
	{
		if (c == '\0')
			return ((char *)s);
		return (NULL);
	}
	return (l);
}
