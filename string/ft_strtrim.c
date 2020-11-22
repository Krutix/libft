/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:15:29 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:39:01 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char		*ft_strtrim(char const *str, char const *set)
{
	size_t	start;
	size_t	len;
	char	*copy;

	start = 0;
	while (str[start] && ft_strchr(set, str[start]))
		start++;
	len = ft_strlen(str);
	if (len != 0)
		while (ft_strchr(set, str[--len]) && len > start)
			(void)len;
	len = len - start + 1;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, str + start, len);
	*(copy + len) ^= *(copy + len);
	return (copy);
}
