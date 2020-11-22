/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:11:54 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:39:07 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char		*ft_substr(char const *src, unsigned int start, size_t len)
{
	char			*sub_str;

	sub_str = malloc(len + 1);
	if (!sub_str)
		return (NULL);
	ft_memcpy(sub_str, src + start, len);
	*(sub_str + len) ^= *(sub_str + len);
	return (sub_str);
}
