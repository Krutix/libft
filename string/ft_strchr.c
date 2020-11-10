/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:58:07 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:25:28 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_string.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char*)--s);
	return (c == '\0' ? (char*)s : NULL);
}
