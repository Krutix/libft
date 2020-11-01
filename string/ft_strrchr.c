/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:56:59 by fdiego            #+#    #+#             */
/*   Updated: 2020/10/31 22:57:05 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *l;

	l = NULL;
	while (*s)
	{
		if (*s == (char)c)
			l = (char*)s;
		s++;
	}
	if (l == NULL)
		return (c == '\0' ? (char*)s : NULL);
	return (l);
}
