/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:29:10 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 09:28:02 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcat(char *dest, char *src)
{
	char	*d;

	d = dest + ft_strlen(dest);
	ft_strcpy(d, src);
	return (dest);
}
