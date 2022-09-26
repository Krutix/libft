/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:15:29 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 09:10:17 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	len;

	while (*str && ft_strchr(set, *str))
		str++;
	len = ft_strlen(str);
	if (len != 0)
		while (len-- != 0 && ft_strchr(set, str[len]))
			(void)len;
	len = len + 1;
	return (ft_substr(str, 0, len));
}
