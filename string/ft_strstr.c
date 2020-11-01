/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:55:36 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/01 21:45:46 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
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
