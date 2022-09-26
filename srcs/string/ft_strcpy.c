/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 11:51:08 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/07 22:14:54 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcpy_s(char *dest, char const *src)
{
	if (dest == NULL || src == NULL)
		return (dest);
	return (ft_strcpy(dest, src));
}

char	*ft_strcpy(char *dest, char const *src)
{
	return (ft_memcpy(dest, src, ft_strlen(src)));
}
