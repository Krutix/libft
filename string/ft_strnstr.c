/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:03:26 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/26 14:48:00 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(char *str, char *to_find, size_t size)
{
	size_t			i;
	size_t			istr;
	const size_t	find_size = ft_strlen(to_find) - 1;

	istr = 0;
	if (to_find[0] == '\0')
		return (str);
	if (find_size < size)
		size -= find_size;
	while (istr < size && str[istr + find_size])
	{
		i ^= i;
		while (str[istr + i] == to_find[i])
			if (to_find[i++ + 1] == '\0')
				return (str + istr);
		istr++;
	}
	return (NULL);
}
