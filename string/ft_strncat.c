/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:13:27 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:26:15 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	unsigned int is;

	i = 0;
	is = 0;
	while (dest[i])
		i++;
	while (is < n && src[is] != '\0')
		dest[i++] = src[is++];
	dest[i] = '\0';
	return (dest);
}
