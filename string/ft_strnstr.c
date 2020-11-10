/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:03:26 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:26:36 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(char *str, char *to_find, size_t size)
{
	size_t	i;
	size_t	isr;

	isr = 0;
	if (to_find[0] == '\0')
		return (str);
	while (isr < size && str[isr])
	{
		i = 0;
		while (str[isr + i] == to_find[i])
		{
			if (to_find[i + 1] == '\0')
				return (str + isr);
			else if (isr + i == size || !str[isr])
				return (NULL);
			i++;
		}
		isr++;
	}
	return (NULL);
}
