/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:03:26 by fdiego            #+#    #+#             */
/*   Updated: 2021/07/27 15:59:15 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char const	*ft_strnstr(char const *str, char const *to_find, size_t size)
{
	size_t			istr;
	const size_t	find_size = ft_strlen(to_find);

	if (to_find[0] == '\0')
		return (str);
	if (find_size > size)
		return (NULL);
	size -= find_size;
	istr = 0;
	while (istr < size && str[istr + find_size - 1])
	{
		if (ft_memcmp(str + istr, to_find, find_size) == 0)
			return (str + istr);
		istr++;
	}
	return (NULL);
}
