/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:45:13 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:26:32 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
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
