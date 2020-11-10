/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:15:29 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:26:49 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int	is_in_charset(char ch, char const *set)
{
	int i;

	if (!set)
		return (1);
	i = 0;
	while (set[i])
		if (ch == set[i++])
			return (1);
	return (0);
}

char		*ft_strtrim(char const *str, char const *set)
{
	size_t start;
	size_t len;

	start = 0;
	if (!str)
		return (NULL);
	while (str[start] && is_in_charset(str[start], set))
		start++;
	len = ft_strlen(str);
	while (is_in_charset(str[--len], set) && len > start)
		(void)len;
	len = len - start + 1;
	return (ft_substr(str, start, len));
}
