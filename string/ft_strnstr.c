/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:03:26 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:38:53 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(char *str, char *to_find, size_t size)
{
	size_t			i;
	size_t			isr;
	const size_t	find_size = ft_strlen(to_find) - 1;

	isr = 0;
	if (to_find[0] == '\0')
		return (str);
	if (find_size < size)
		size -= find_size;
	while (isr < size && str[isr + find_size])
	{
		i ^= i;
		while (str[isr + i] == to_find[i])
			if (to_find[i++ + 1] == '\0')
				return (str + isr);
		isr++;
	}
	return (NULL);
}
