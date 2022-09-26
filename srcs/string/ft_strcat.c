/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:29:10 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/07 22:10:45 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcat_s(char *dest, char const *src)
{
	if (dest == NULL || src == NULL)
		return (NULL);
	return (ft_strcat(dest, src));
}

char	*ft_strcat(char *dest, char const *src)
{
	char	*d;

	d = dest + ft_strlen(dest);
	ft_strcpy(d, src);
	return (dest);
}
