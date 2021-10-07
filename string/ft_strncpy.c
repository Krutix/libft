/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:45:13 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/07 22:43:40 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strncpy(char *dest, char const *src, unsigned int n)
{
	if (dest == NULL || src == NULL)
		return (dest);
	return (ft_strncpy(dest, src, n));
}

char	*ft_strncpy(char *dest, char const *src, unsigned int n)
{
	unsigned int	i;
	int				term;

	i = 0;
	term = 0;
	while (i < n)
	{
		if (src[i] == '\0')
			term = 1;
		if (term == 0)
			dest[i] = src[i];
		else
			dest[i] = '\0';
		i++;
	}
	return (dest);
}
