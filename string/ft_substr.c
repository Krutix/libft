/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:11:54 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:26:53 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char		*ft_substr(char const *src, unsigned int start, size_t len)
{
	char			*sub_str;
	char const		*s;
	unsigned int	i;

	sub_str = malloc(len + 1);
	s = src;
	if (!sub_str || !s)
		return (NULL);
	while (*s && start != 0)
	{
		start--;
		s++;
	}
	i = 0;
	while (i < len)
	{
		if ((sub_str[i] = s[i]) == '\0')
			return (sub_str);
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
