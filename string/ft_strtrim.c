/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:15:29 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/26 14:59:51 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char		*ft_strtrim(char const *str, char const *set)
{
	size_t	len;
	char	*copy;

	while (*str && ft_strchr(set, *str))
		str++;
	len = ft_strlen(str);
	if (len != 0)
		while (len-- != 0 && ft_strchr(set, str[len]))
			(void)len;
	len = len + 1;
	return (ft_substr(str, 0, len));
}
