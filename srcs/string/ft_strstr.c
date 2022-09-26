/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:55:36 by fdiego            #+#    #+#             */
/*   Updated: 2021/07/27 15:59:06 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_string.h"

char const	*ft_strstr(char const *str, char const *to_find)
{
	size_t	i;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		i = 0;
		while (str[i] == to_find[i])
		{
			i++;
			if (to_find[i] == '\0')
				return (str);
			else if (str[i] == '\0')
				return (NULL);
		}
		str++;
	}
	return (NULL);
}
