/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:13:27 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/26 14:45:45 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	ft_memccpy(dest + ft_strlen(dest), src, '\0', n);
	return (dest);
}
