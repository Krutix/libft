/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:13:27 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/07 22:37:29 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strncat_s(char *dest, char const *src, unsigned int n)
{
	if (dest == NULL || src == NULL)
		return (dest);
	return (ft_strncat(dest, src, n));
}

char	*ft_strncat(char *dest, char const *src, unsigned int n)
{
	ft_memccpy(dest + ft_strlen(dest), src, '\0', n);
	return (dest);
}
